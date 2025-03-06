# ECS34Project1

Throughout the course of this project, I did use the website and the resources that the professor provided me. 
However, for the test cases that I wrote, I referenced my ECS 32C professor's test cases and learned about the EXPECT_EQ from there. That is why I implemented it like this. 

The professor provided us with a website, which I found helpful throughout the course of this assignment. 

For the first function in StringUtils.cpp, I used the website to understand sub.str. Here is the link: https://cplusplus.com/reference/string/string/substr/ , https://cplusplus.com/forum/beginner/82077/

For the capitalize function, I referenced the DevelopmentFlowWorksheet.pdf on Canvas and found the code for capitalization via there. 

For the upper and lower function in StringUtils.cpp, I used these links from the website: https://cplusplus.com/reference/cctype/toupper/?kw=toupper, https://cplusplus.com/reference/cctype/tolower/

For Lstrip and Rstrip, I used the std::isspace function and pulled these links from the website: https://cplusplus.com/reference/cctype/isspace/?kw=isspace

For Lstrip and Rstrip, I did reference stackoverflow to see the python version to help refresh my memory a bit. The link is here: https://stackoverflow.com/questions/8270092/remove-all-whitespace-in-a-string


For LJust and RJust, I ended up reviewing different functions to figure out how to return the justified strings. Here is a link I used from the website: https://cplusplus.com/reference/string/string/string/ and this one helped too: https://cplusplus.com/forum/beginner/233668/

For replace, I used this link from the website to help me and the sample code: https://cplusplus.com/reference/string/string/replace/ & https://cplusplus.com/reference/string/string/find/ & https://cplusplus.com/forum/general/49520/#google_vignette

For the split function, I learned about emplace_back, push_back and find_first_of from this sample code on the website: https://cplusplus.com/forum/beginner/114790/ and I also used these to learn about emplace_back, find_first_of: https://cplusplus.com/reference/vector/vector/emplace_back/, https://cplusplus.com/reference/string/string/find_first_of/, and https://cplusplus.com/reference/string/string/push_back/

For ExpandTabs, https://cplusplus.com/reference/string/string/string/


For the EditDistance, I referenced the wikipedia page given by the professor to us. Here is the link: https://en.wikipedia.org/wiki/Levenshtein_distance. I also used this link from the website: https://cplusplus.com/reference/vector/vector/



I also asked ChatGPT to generate some more examples for me and wanted to check if my assumptions were correct. 
Part of wiki page i wass confused by: 


Input: in levenshtein distance why is the distance between kitten and sitting 3

GPT Response: Great question! Let's break it down step by step to see why the Levenshtein distance between "kitten" and "sitting"is 3.
Strings:
String 1: "kitten"
String 2: "sitting"
The goal is to transform "kitten" into "sitting" using the fewest possible edits. The allowed operations are:
Insertion – inserting a character.
Deletion – deleting a character.
Substitution – replacing one character with another.
Step-by-Step Transformation:
We’ll look at each step of transforming "kitten" into "sitting". We’ll perform the minimum number of operations at each step.
Substitute 'k' with 's':
"kitten" → "sitten"
This is the first operation, a substitution, changing "k" to "s".
Insert 'i':
"sitten" → "sittin"
This is the second operation, an insertion, adding the "i" at the end.
Insert 'g':
"sittin" → "sitting"
This is the third operation, an insertion, adding the "g" at the end.
Summary of the Operations:
Substitution: 'k' → 's' (1 operation)
Insertion: 'i' (1 operation)
Insertion: 'g' (1 operation)
Thus, the Levenshtein distance between "kitten" and "sitting" is 3 because it took 3 operations (1 substitution + 2 insertions) to transform the first string into the second.
Visualizing the Process:
You can visualize this as a sequence of edits:
"kitten" → "sitten" (1 substitution: k → s)
"sitten" → "sittin" (1 insertion: i)
"sittin" → "sitting" (1 insertion: g)
The total number of edits is 3, which is why the Levenshtein distance is 3.
Why not fewer than 3 edits?
If you tried to perform fewer than 3 operations, you wouldn’t be able to turn "kitten" into "sitting" because each change to one string must correspond to a valid edit operation (insert, delete, or substitute) and there’s no way to reduce the number of operations further. This is what makes the Levenshtein distance a useful and meaningful metric!

Let me know if you need more details or another example!




Other questions I asked ChatGPT: 

My input: im confused how std::vector works with an std::string like in my code i currently have a test case written like std::vector<std::string> ch = ("dog", cat") 

Chatgpt response: It looks like there’s a small syntax issue in your code snippet. In C++, to initialize a std::vector<std::string>, you need to use curly braces {} instead of parentheses ().
Here's the corrected version:
std::vector<std::string> ch = {"dog", "cat"};

Explanation:
std::vectorstd::string is a vector that stores strings (std::string objects). It can dynamically resize as elements are added or removed.
When you initialize it with {"dog", "cat"}, you are using an initializer list, which allows you to initialize the vector with multiple values at once.
Why it doesn't work with parentheses:
In C++, parentheses () are used for function calls or object constructors. The line ("dog", "cat") doesn't match what the compiler expects, which is why it gives an error.
To summarize, to create a vector of strings, you need to use curly braces:
std::vector<std::string> ch = {"dog", "cat"};

Does that clear things up? Let me know if you need further explanation or run into any other issues!





My input : also i keep getting an error in my <include #filename> how do i fix that?

You're welcome! I assume you're referring to an error in your #include directive in your code. There are a few common issues that can occur with the #include directive, especially when including header files like #include <filename>.
Let’s go through some of the typical issues and solutions:
1. Incorrect Header File Path
If you're including a file like #include <filename>, but it's not found by the compiler, the issue may be that the file isn't in one of the standard system directories or your project’s include directories.
Solution:
For system headers, ensure that the header file is part of the library or framework you're trying to include.
For custom headers, if you’re including your own files, ensure you're using the correct path relative to the file you're working with. For example:
#include "my_header.h"  // Correct for user-defined headers

Here, "my_header.h" is a custom file that should be in the same directory as your source file or in an include directory that your compiler can access.
If you're trying to include a custom header and it’s located in a different directory, you can specify the relative path like:
#include "path/to/my_header.h"

Or, you can modify the compiler’s include path so it knows where to look for headers. If you're using g++, for example, you can pass the include path with -I:
g++ -I/path/to/header/ my_program.cpp -o my_program

2. Misplaced Angle Brackets vs Quotes
Angle Brackets (< >) are used for system libraries or standard library headers, like:
#include <iostream>
#include <vector>
The compiler will look for these in the standard system include directories.
Quotes (" ") are used for user-defined header files or libraries that you have written, such as:
#include "my_header.h"
The compiler first looks in the current directory for "my_header.h", then in the directories specified by the -I flag, and then in the standard include paths.
If you use < > for a user-defined header, it won't work unless the header is located in a system directory or a directory you’ve specifically told the compiler to search using the -I flag.
3. Case Sensitivity (Especially on Linux and macOS)
Make sure that the header file’s name matches exactly, including capitalization, as file systems on Linux and macOS are case-sensitive, but Windows is not.
For example, if the header file is named my_header.H (with a capital H), #include "my_header.h" will not work on Linux or macOS, but it will on Windows.
Solution:
Make sure the filename in the #include directive matches the actual file's name exactly.
4. Circular Dependencies Between Headers
If two header files include each other, you can create a circular dependency, which will cause the compiler to get confused.
For example, in this situation:
// FileA.h
#include "FileB.h"

// FileB.h
#include "FileA.h"

This will lead to a circular inclusion, resulting in errors.
Solution:
To prevent circular dependencies, use forward declarations instead of including headers directly when possible:
// FileA.h
class FileB;  // Forward declaration

In FileB.h, you can then include FileA.h because the forward declaration tells the compiler about FileA's existence without needing the full details.
5. Incorrect or Missing Compiler Flags
If you’re using libraries that require special flags to be linked, make sure you’re including the correct flags. For example:
For Google Test (gtest), you need to link the library:
g++ -lgtest -lgmock -pthread my_test.cpp -o my_test
This tells the compiler to link Google Test’s libraries during the compilation.
6. Missing or Incorrectly Installed Dependencies
If you’re trying to include a library header (like #include <gtest/gtest.h> for Google Test), and the library isn’t properly installed or isn’t available in the expected location, you’ll get an error.
Solution:
Make sure that:
The library is installed correctly (using apt-get, brew, or manually).
The header files and libraries are in the correct locations.
You have included the necessary directories via the -I flag for headers and -L flag for libraries when compiling.
For example, if you installed Google Test via vcpkg, you should ensure that your compiler can find it by including the right path, e.g.,:
g++ -I/path/to/vcpkg/installed/x64-linux/include my_test.cpp -o my_test -L/path/to/vcpkg/installed/x64-linux/lib -lgtest -lgmock -pthread


7. Preprocessor Directives or Compiler Errors
Sometimes errors come from preprocessor issues or misconfigurations. For example, if you're missing a closing quote ("), or you accidentally use angle brackets when quotes are needed (or vice versa), it could cause issues.
Check for things like:
Unmatched #include directives (e.g., missing closing " or </>).
Typographical errors in the header filename.

Summary of Fixes:
For system headers, use < >:
#include <iostream>


For user-defined headers, use " ":
#include "my_header.h"


Check your include paths and ensure the file exists in the correct location.
Ensure there are no circular dependencies in header files.
Make sure you are using the correct compiler flags if linking external libraries.
If you're still getting errors after making these checks, feel free to share the specific error message or code snippet, and I can help you troubleshoot further!





