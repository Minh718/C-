#include<iostream>
#include <string.h>
using namespace std;
class Book
{
private:
char* title;
    char* authors;
    int publishingYear;

public:
    Book()
    {
    title=NULL;
    authors=NULL;
    publishingYear = 0;
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        this->title = new char[strlen(title)+1];
        for(size_t i=0;i<=strlen(title);i++){
         this->title[i]=title[i];
        }
        this->authors = new char[strlen(authors)];
        for(size_t i=0;i<strlen(authors);i++){
         this->authors[i]=authors[i];
        }
        this->publishingYear=publishingYear;
    }

    Book(const Book &book)
    {
        this->title = new char[strlen(book.title)];
        for(size_t i=0;i<strlen(book.title);i++){
         this->title[i]=book.title[i];
        }
        this->authors = new char[strlen(book.authors)];
        for(size_t i=0;i<strlen(book.authors);i++){
         this->authors[i]=book.authors[i];
        }
        this->publishingYear=book.publishingYear;
    }

    void setTitle(const char* title)
    {
        this->title = new char[strlen(title)];
        for(size_t i=0;i<strlen(title);i++){
         this->title[i]=title[i];
        }
    }

    void setAuthors(const char* authors)
    {
      this->authors = new char[strlen(authors)];
        for(size_t i=0;i<strlen(authors);i++){
         this->authors[i]=authors[i];
    }
    }

    void setPublishingYear(int publishingYear)
    {
      this->publishingYear=publishingYear;
    }

    char* getTitle() const
    {
        return this->title;
    }

    char* getAuthors() const
    {
        return this->authors;
    }

    int getPublishingYear() const
    {
        return this->publishingYear;
    }

    ~Book()
    {
        /*
         * STUDENT ANSWER
         */
    }

    void printBook(){
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};
int main(){
Book book1("Giai tich 1","Nguyen Dinh Huy",2000);
book1.printBook();
}
