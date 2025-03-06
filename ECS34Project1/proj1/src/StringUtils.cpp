#include "StringUtils.h"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    int l = str.length(); //initated a variable for lenght 
    if (start <= 0){
        start += l; //this ultimately checks the bounds
    }
    if (end <= 0){ 
        end+= l; //if end is less than 0 then update end to reach length 
    }
    if (start < 0){ 
        return 0; //again checking for negative bound
    }
    if (end > l){ 
        end = l;  //if end is less than the string length then end is just set equal
    }
    if (start >= end){  //this condition just returns nothing 
        return""; }
    
    return str.substr(start, end-start); //substr is found from website and cited here and it just extracts the certain part of the string 

}

std::string Capitalize(const std::string &str) noexcept{
    std::string r;
    for (auto ch: str){ //iterate through the string
        r += tolower(ch);  //you need to lowercase everything
   }
   r[0] = toupper(r[0]); //index through and capitalize only the first letter
   return r;
}

std::string Upper(const std::string &str) noexcept{
    std::string up;  //initialize a variable called up 
    up.reserve(str.size()); //i found reerve off the website 
    for (char c: str ){ 
        up += std::toupper(static_cast<unsigned char>(c)); //we need to assign up to make sure std::toupper converts all unsigned character to uppercase 
    }
   return up; //if so then we return the uppercase elements 

}

std::string Lower(const std::string &str) noexcept{
    std:: string lower; //establish string lower
    lower.reserve(str.size()); //need to ensure size of string stays same 
    for (char c: str){ //iterate through 
        lower += std::tolower(static_cast<unsigned char>(c)); //again, we used std::tolower to convert everything to lowercase
   }
   return lower; //return all lowercased letters 
}

std::string LStrip(const std::string &str) noexcept{
    size_t ind = 0; //set an index = 0 
    //while index is less than string length and isspace (found from website)
    while (ind < str.length() && std::isspace(static_cast<unsigned char>(str[ind]))){//used isspace from the website 
        ind++; //iterate through because we are strpping through left 
   }
   return str.substr(ind); //return the actual values without whitespace 
}

std::string RStrip(const std::string &str) noexcept{
    size_t ind = str.length(); //we want to capture string's full length (initialized and index for the string lenght)
    while (ind > 0 && std::isspace(static_cast<unsigned char>(str[ind - 1]))){
        ind--; //using isspace we extract the spaces 
   }
   return str.substr(0, ind); //substrip the 0 to index to return the string 
}


std::string Strip(const std::string &str) noexcept{
    return LStrip(RStrip(str));; //to fully strip call on both lstrip + rstrip to fully strip the whitespace off the string 
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    if ((str.size() >=  (width))){ //if width less than or equal to size 
        return str;
    } 
    int total = width -str.size();  //form a total that is the width subtracted from the 
    int left = total/2; 
    std::string final(left,fill); //fill acts as 
    final += str; 
    final.append(total-left, fill ); //i used fill from the website --> 
    return final; 

}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    if ((str.size() >= width)){
        return str; //if string wider or equal just return original string 
    }
    return str + std::string(width-str.size(), fill); //we get to append the fill characters to right 
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    if ((str.size() >= width)){ //bounds checking else return string 
       return str;
   }
   return std::string(width-str.size(), fill)+str; //this would simply return the strin + a new string of number of spaces  
   //understood std::string function for fill via webstite
}



std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    std:: string result = str; //this creates the string 
    size_t position = 0; //initialize position 
    while (position < result.size()){ //bounds checking 
        position = result.find(old, position); 
        if (position < result.size()){
            result.replace(position, old.length(), rep);
            position += rep.length(); //resize the position 
        } else{
            break;
       }
   }
   return result;

}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    size_t index = 0; //initialize an index 
    size_t end = str.find(splt); //found find_first of in the website 
    std::vector<std::string> output; //needed to create a vector output 
    while (end != std:: string::npos){ //checks until no delimiter found 
        output.push_back(str.substr(index, end-index)); //this gets substring for us 
        index = end +splt.length(); //index continues to iterate thru 
        end = str.find(splt,index); //find the next char 
    }
    output.emplace_back(str.substr(index)); //inputs final part of string 
    return output;
}


std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    std:: string result; //intialize string 
    for (size_t index = 0; index < vect.size(); ++index){
        result += vect[index]; //iterate vect to string 
        if (index < vect.size()-1){
            result += str; 
        }
    }
    return result; //outputs a string 

}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::string output; //initialize that output is a string 
    int ind = 0; //index is set to 0 
    for (char c: str){ //iterate thru 
        if (c == '\t'){ //base case --> if c is some tab 
            if (tabsize == 0){
                continue; 
            } else {
                int sp = tabsize - (ind % tabsize); //then we initialize space which subtracts index mod tabsize 
                output += std::string(sp,' '); //this just updates output 
                ind += sp; //index also takes in numerical value of space s
            }
        } else {
            output += c;//output results with the characters // string output 
            ind++; //index grows 
        }
    }
    return output;

}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{ 
    std::string l; //need to initialize a "left side" and a "right"
    std::string rt; 

    if (ignorecase){ //if its false then 
        l = Upper(left); //begin by uppercasing both --> called on the upper function 
        rt = Upper(right); 
    } else{ //otherwise stays same 
        l = left; 
        rt = right; 
    }
    if(l.empty()){ //if the left is empty then we return the integer value of the right 
        return int(rt.length()); 
    } else if (rt.empty()){ //vise versa; if the right is empty then return integer value of the left 
        return int(l.length()); 
    } else if (l[0] == rt[0]){ //if we have the same length then u call on EditDistance to slice through 
        return EditDistance(Slice(l,1,0), Slice(rt,1,0),ignorecase); 
    }
    
    std::vector<int> distance = {EditDistance(Slice(l,1,0),rt), EditDistance(l,Slice(rt,1,0)), EditDistance(Slice(l,1,0), Slice(rt,1,0))}; 
    int minimum = distance[0]; 
    for (int i = 1; i < distance.size(); ++i){
        if (distance[i]<minimum){
            minimum = distance[i]; 
        }
    }
    return 1+minimum; 
}

}; 