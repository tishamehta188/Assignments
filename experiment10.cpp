#include <iostream>
#include <map>
#include <string>

class BookLibrary {
private:
    std::map<std::string, std::string> books; 
public:
    
    BookLibrary() {
      
        books["9780132350884"] = "The C++ Programming Language";
        books["9780321563842"] = "Effective C++";
        books["9780201616224"] = "Design Patterns: Elements of Reusable Object-Oriented Software";
        books["9780201835953"] = "The Mythical Man-Month";
    }

   
    void searchBook(const std::string &isbn) {
        auto it = books.find(isbn);
        if (it != books.end()) {
            std::cout << "Book found!\n";
            std::cout << "Title: " << it->second << std::endl;
        } else {
            std::cout << "Book with ISBN " << isbn << " not found in the library.\n";
        }
    }
};

int main() {
    BookLibrary library;

    std::string inputISBN;
    std::cout << "Enter the ISBN of the book to search: ";
    std::cin >> inputISBN;

    library.searchBook(inputISBN);

    return 0;
}

