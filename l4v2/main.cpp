#include <iostream>

int _strcmp(const char *str1, const char *str2)
{
    while (*str1 != '\0' && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    unsigned char c1 = (unsigned char)(*str1);
    unsigned char c2 = (unsigned char)(*str2);

    if (c1 < c2) return -1;
    if (c1 > c2) return 1;
    return 0;
}

int my_strlen(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

bool is_digit_word(const char *word)
{
    if (word[0] == '\0') return false;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] < '0' || word[i] > '9')
        {
            return false;
        }
    }
    return true;
}

void reorder_words(char *str)
{
    struct Word
    {
        char text[301];
        bool is_digit;
    } words[300];

    int word_count = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        int char_i = 0;

        while (str[i] != ' ' && str[i] != '\0')
        {
            words[word_count].text[char_i++] = str[i++];
        }
        words[word_count].text[char_i] = '\0';

        words[word_count].is_digit = is_digit_word(words[word_count].text);
        word_count++;

        if (str[i] == ' ')
        {
            i++;
        }
    }

    int out_i = 0;
    bool first_word = true;

    for (int k = 0; k < word_count; k++)
    {
        if (words[k].is_digit)
        {
            if (!first_word)
            {
                str[out_i++] = ' ';
            }
            int len = my_strlen(words[k].text);
            for (int j = 0; j < len; j++)
            {
                str[out_i++] = words[k].text[j];
            }
            first_word = false;
        }
    }

    for (int k = 0; k < word_count; k++)
    {
        if (!words[k].is_digit)
        {
            if (!first_word)
            {
                str[out_i++] = ' ';
            }
            int len = my_strlen(words[k].text);
            for (int j = 0; j < len; j++)
            {
                str[out_i++] = words[k].text[j];
            }
            first_word = false;
        }
    }

    str[out_i] = '\0';
}

int main()
{
    std::cout << "Task A \n";
    const char *s1 = "fttyf";
    const char *s2 = "fttz";
    const char *s3 = "uhiuiyg";
    const char *s4 = "fttyf";
    std::cout << "_strcmp(\"" << s1 << "\", \"" << s2 << "\") = " << _strcmp(s1, s2) << " \n";
    std::cout << "_strcmp(\"" << s2 << "\", \"" << s1 << "\") = " << _strcmp(s2, s1) << " \n";
    std::cout << "_strcmp(\"" << s1 << "\", \"" << s3 << "\") = " << _strcmp(s1, s3) << " \n";
    std::cout << "_strcmp(\"" << s1 << "\", \"" << s4 << "\") = " << _strcmp(s1, s4) << " \n";

    std::cout << "Task B \n";
    std::cout << "Enter line:\n";
    char strinp[301];
    std::cin.getline(strinp, 301);
    reorder_words(strinp);
    std::cout << "Result:\n" << strinp << std::endl;

    return 0;
}
