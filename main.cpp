#include <iostream>
#include <time.h>

using namespace std;

unsigned short num_digits (unsigned long long number);

int main() {
    clock_t begin, end;
    unsigned int number_of_pages, min_page = 1, max_page = 9, number_of_digits = 0;
    unsigned short max_digits, iterate;

    cout << "How many pages are there in the book?: ";
    cin >> number_of_pages;

    begin = clock();
    max_digits = num_digits(number_of_pages);

    for (iterate = 1; iterate <= max_digits; iterate++)
    {
        if (number_of_pages < max_page)
            max_page = number_of_pages;

        number_of_digits += ((max_page - min_page) + 1) * iterate;
        min_page *= 10;
        max_page = (max_page * 10) + 9;
    }

    cout << "Number of digits: " << number_of_digits << endl;

    end = clock();
    cout << "Time: " << (end - begin) / (double) CLOCKS_PER_SEC << endl;

    return 0;
}

unsigned short num_digits (unsigned long long number)
{
    unsigned short digits = 0;

    while (number) {
        digits++;
        number /= 10;
    }

    return digits;
}
