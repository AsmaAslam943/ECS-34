#include "DSVReader.h"
#include <sstream>

// internal struct for managing reader state
struct CDSVReader::SImplementation {
    std::shared_ptr<CDataSource> source; // data source from which we read
    char delimiter;  // char used to split fields in a row
    bool end_of_file; //  to check if we've reached the end of the file

    // constructor initializes the data source and delimiter, sets EOF flag to false
    SImplementation(std::shared_ptr<CDataSource> s, char d)
        : source(s), delimiter(d), end_of_file(false) {}
};


CDSVReader::CDSVReader(std::shared_ptr<CDataSource> src, char delimiter) // constructor
    : DImplementation(std::make_unique<SImplementation>(src, delimiter)) {}


CDSVReader::~CDSVReader() = default; // destructor

bool CDSVReader::End() const {  // checks if we have reached EOF
    return DImplementation->end_of_file;
}

// reads a row from the data source and splits it into fields
bool CDSVReader::ReadRow(std::vector<std::string> &row) {
    if (!DImplementation->source || DImplementation->end_of_file) {
        return false; // ret false if the source is unavail or alr hit EOF
    }

    std::vector<char> buffer; // buffer to store raw data from the source
    constexpr std::size_t buffer_size = 1024;  // limit buffer size to 1024 bytes

    if (!DImplementation->source->Read(buffer, buffer_size)) { // try to read from the source into the buffer
        DImplementation->end_of_file = true; // mark EOF if reading fails
        return false;
    }

    std::string line(buffer.begin(), buffer.end()); // convert buffer content into a string for easier processing
    std::istringstream line_stream(line);
    std::string field;

    
    while (std::getline(line_stream, field, DImplementation->delimiter)) { // split the line into fields using the delimiter
        row.push_back(field);
    }

    return !row.empty(); // ret true if we successfully extracted fields
}
