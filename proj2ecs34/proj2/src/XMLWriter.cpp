#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <stdexcept> 
#include <expat.h>
#include "XMLWriter.h"
#include "StringDataSource.h"



struct CXMLWriter::SImplementation {
   std::shared_ptr<CDataSink> DSink;
   std::vector<std::string> OpenTags; 
   XML_Parser Parser; 



   SImplementation(std::shared_ptr<CDataSink> sink) : DSink(sink){
   }

   ~SImplementation(){
   }
    

   void WriteStartElement(const SXMLEntity &entity){
       std::ostringstream os;
       os << "<" << entity.DNameData;
       for (const auto &attr : entity.DAttributes){
           os << " " << attr.first << "=\""<< attr.second << "\"";
       }
       os << ">";
       std::string str = os.str();
       std::vector<char>data(str.begin(), str.end()); 
       DSink ->Write (data);
       OpenTags.push_back(entity.DNameData);
   }


   void WriteEndElement(const SXMLEntity &entity){
       if (!OpenTags.empty() && OpenTags.back() == entity.DNameData){
           std::ostringstream os;
           os << "</" << entity.DNameData << ">";
           std:: string str = os.str(); 
           std::vector<char> data(str.begin(), str.end()); 
           DSink->Write(data);
           OpenTags.pop_back();
       }
   }


   void WriteCompleteElement(const SXMLEntity &entity){
       std::ostringstream os;
       os << "<" << entity.DNameData;
       for (const auto &attr : entity.DAttributes){
           os << " " << attr.first << "=\"" << attr.second << "\"";
       }
       os << "/>";
       std::string str = os.str(); 
       std::vector<char>data(str.begin(), str.end()); 
       DSink ->Write(data);
   }


};


// Constructor for XML writer, sink specifies the data destination

CXMLWriter::CXMLWriter(std::shared_ptr<CDataSink>sink)
   : DImplementation(std::make_unique<SImplementation>(sink)){}


CXMLWriter::~CXMLWriter(){
   Flush();
}
// Outputs all end elements for those that have been started
bool CXMLWriter::Flush(){
   while(!DImplementation->OpenTags.empty()){
        std::string tag = DImplementation->OpenTags.back(); 
        std::ostringstream os;
        
        os << "</" << tag << ">";
        std::string str = os.str(); 
        std::vector<char> data(str.begin(), str.end()); 
        DImplementation->DSink->Write(data);  
        DImplementation->OpenTags.pop_back(); 
   }
   return true;
}

// Writes out the entity to the output stream
bool CXMLWriter::WriteEntity(const SXMLEntity &entity){
   switch(entity.DType){
    case SXMLEntity::EType::StartElement:
       DImplementation->WriteStartElement(entity);
       break;
   case SXMLEntity::EType::EndElement:
       DImplementation->WriteEndElement(entity);
       break;
   case SXMLEntity::EType::CompleteElement:
       DImplementation->WriteCompleteElement(entity);
       break;
   default:
       return false;
   }
   return true;
}


