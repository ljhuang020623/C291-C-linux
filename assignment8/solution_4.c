#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[10];
    char author[100];
    char title[200];
    char genre[50];
    double price;
    char publish_date[15];
    char description[500];
} Book;

void extractContent(char *dest, const char *src, const char *startTag, const char *endTag) {
    char *start = strstr(src, startTag);
    char *end = strstr(src, endTag);
    if (start && end) {
        start += strlen(startTag);
        strncpy(dest, start, end - start);
        dest[end - start] = '\0';
    }
}

int main(void) {
    char *xmlString =
"<?xml version=\"1.0\"?>\n<catalog>\n"
"<book id=\"bk101\">\n"
"<author>Gambardella, Matthew</author>\n"
"<title>XML Developer's Guide</title>\n"
"<genre>Computer</genre>\n"
"<price>44.95</price>\n"
"<publish_date>2000-10-01</publish_date>\n"
"<description>An in-depth look at creating applications with XML.</description>\n"
"</book>\n"
"<book id=\"bk102\">\n"
"<author>Cormen, Stein</author>\n"
"<title>Introduction of Algorithm, fourth edition</title>\n"
"<genre>Computer</genre>\n"
"<price>84.89</price>\n"
"<publish_date>2022-04-05</publish_date>\n"
"<description>A comprehensive update of the leading algorithms text, with new material on matchings in bipartite graphs, online algorithms, machine learning, and other topics.</description>\n"
"</book>\n"
"<book id=\"bk103\">\n"
"<author>Ryan, Carl</author>\n"
"<title>Python Programming for beginners: A Crash Course</title>\n"
"<genre>Computer</genre>\n"
"<price>7.11</price>\n"
"<publish_date>2022-01-19</publish_date>\n"
"<description>The Ultimate Python guide for beginners!</description>\n"
"</book>\n"
"</catalog>";

    Book books[10];
    int bookCount = 0;

    char *bookStart = strstr(xmlString, "<book");
    while (bookStart) {
        char *bookEnd = strstr(bookStart, "</book>");
        if (!bookEnd) break;

        char bookContent[2000];
        strncpy(bookContent, bookStart, bookEnd - bookStart + 7);
        bookContent[bookEnd - bookStart + 7] = '\0';

        extractContent(books[bookCount].id, bookContent, "id=\"", "\">");
        extractContent(books[bookCount].author, bookContent, "<author>", "</author>");
        extractContent(books[bookCount].title, bookContent, "<title>", "</title>");
        extractContent(books[bookCount].genre, bookContent, "<genre>", "</genre>");
        char priceStr[10];
        extractContent(priceStr, bookContent, "<price>", "</price>");
        books[bookCount].price = atof(priceStr);
        extractContent(books[bookCount].publish_date, bookContent, "<publish_date>", "</publish_date>");
        extractContent(books[bookCount].description, bookContent, "<description>", "</description>");

        bookCount++;
        bookStart = strstr(bookEnd, "<book");
    }

    if (bookCount == 0) {
        printf("No books found in the XML.\n");
        return 0;
    }

    int mostExpensiveIndex = 0;
    int leastExpensiveIndex = 0;

    for (int i = 1; i < bookCount; i++) {
        if (books[i].price > books[mostExpensiveIndex].price) mostExpensiveIndex = i;
        if (books[i].price < books[leastExpensiveIndex].price) leastExpensiveIndex = i;
    }

    printf("Most Expensive Book:\n");
    printf("Author: %s\n", books[mostExpensiveIndex].author);
    printf("Title: %s\n", books[mostExpensiveIndex].title);
    printf("Genre: %s\n", books[mostExpensiveIndex].genre);
    printf("Price: %.2lf\n", books[mostExpensiveIndex].price);
    printf("Publication Date: %s\n", books[mostExpensiveIndex].publish_date);
    printf("Description: %s\n", books[mostExpensiveIndex].description);

    printf("\nLeast Expensive Book:\n");
    printf("Author: %s\n", books[leastExpensiveIndex].author);
    printf("Title: %s\n", books[leastExpensiveIndex].title);
    printf("Genre: %s\n", books[leastExpensiveIndex].genre);
    printf("Price: %.2lf\n", books[leastExpensiveIndex].price);
    printf("Publication Date: %s\n", books[leastExpensiveIndex].publish_date);
    printf("Description: %s\n", books[leastExpensiveIndex].description);

    return 0;
}

