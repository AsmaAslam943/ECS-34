#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <expat.h> 
#include "XMLReader.h"
#include "StringDataSource.h"

struct CXMLReader::SImplementation{
    std::shared_ptr<CDataSource> DDataSource; 
    XML_Parser DParser; 
    bool DEnd; 

    SImplementation(std::shared_ptr< CDataSource > src) : DDataSource(src), DEnd(false) {
        DParser = XML_ParserCreate(nullptr); 
        if (!DParser){
            throw std::runtime_error("Failed to create XML Parser"); 
    }
    XML_SetUserData(DParser, this); 
    XML_SetElementHandler(DParser, StartElementHandler, EndElementHandler); 
    XML_SetCharacterDataHandler(DParser, CharacterDataHandler);
}


~SImplementation(){
    if (DParser){
        XML_ParserFree(DParser); 
    }
}

static void XMLCALL StartElementHandler(void *userData, const XML_Char *name, const XML_Char **atts) {
    auto *impl = static_cast<CXMLReader *>(userData);
    // Create and populate entity
    SXMLEntity entity;
    entity.DType = SXMLEntity::EType::StartElement;
    entity.DNameData = name;
    for (int i = 0; atts[i]; i += 2) {
        entity.DAttributes.push_back({atts[i], atts[i + 1]});
    }
    // Handle the entity as needed (e.g., pass it to some handler function)
}


static void XMLCALL EndElementHandler(void *userData, const XML_Char *name) {
    auto *impl = static_cast<SImplementation*>(userData);
    // Create and populate entity
    SXMLEntity entity;
    entity.DType = SXMLEntity::EType::EndElement;
    entity.DNameData = name;
    // Handle the entity as needed (e.g., pass it to some handler function)
}

static void XMLCALL CharacterDataHandler(void *userData, const XML_Char *s,int len ) {
    auto *impl = static_cast<SImplementation *>(userData);
    // Create and populate entity
    SXMLEntity entity;
    entity.DType = SXMLEntity::EType::CompleteElement;
    entity.DNameData.assign(s,len); 
    // Handle the entity as needed (e.g., pass it to some handler function)
}
}; 


CXMLReader::CXMLReader(std::shared_ptr<CDataSource> src)
    :DImplementation(std::make_unique<SImplementation>(src)){}


    // Destructor for XML reader
CXMLReader::~CXMLReader() = default; 

    // Returns true if all entities have been read from the XML
bool CXMLReader::End() const{
    return DImplementation->DEnd; 
}
    // Returns true if the entity is successfully read if skipcdata
    // is true only element type entities will be returned
bool CXMLReader::ReadEntity(SXMLEntity &entity, bool skipcdata){
    std::vector<char> buffer(4096); 

    while (!DImplementation->DEnd && DImplementation->DDataSource ->Read(buffer, sizeof(buffer))){
        if (XML_Parse(DImplementation->DParser, buffer.data(), sizeof(buffer), DImplementation-> DDataSource->End()) == XML_STATUS_ERROR){
            DImplementation->DEnd = true; 
            return false; 

        }
    }
    return !DImplementation->DEnd; 
};