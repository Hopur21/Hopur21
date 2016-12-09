#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

/**
 * This file contains constants that this application uses
 */

namespace constants {

    //Consts for our datalayer (Text datalayer)
    const char DELIMETER = ';';

    //Menu for Console GUI
    const char SPACE = ' ';
    const int FIRST_TIME = 0;
    const int VALID = 1;
    const int INVALID = 0;
    const int EMPTY_LIST = 0;
    const int INT_COMPUTER = 1;
    const int INT_SCIENTIST = 2;
    const std::string EMPTY_STRING = "";
    const std::string SEARCH_BY_NAME = "1";
    const std::string SEARCH_BY_YEAR_OF_BIRTH = "2";
    const std::string SEARCH_BY_YEAR_OF_DEATH = "3";
    const std::string GENDER_MALE = "1";
    const std::string GENDER_FEMALE = "2";
    const std::string GENDER_OTHER = "3";
    const std::string ALIVE = "0";
    const std::string GO_BACKSTRING = "0";
    const std::string DISPLAY_LIST = "1";
    const std::string ADD = "3";
    const std::string SEARCH = "2";
    const std::string REMOVE = "4";
    const std::string SORT_ALPHABET = "1";
    const std::string SORT_DESCENDING_ALPHABET = "2";
    const std::string SORT_BY_YEAR_OF_BIRTH = "3";
    const std::string SORT_BY_ASCENDING_YEAR_OF_BIRTH = "4";
    const std::string SORT_BY_YEAR_OF_DEATH = "5";
    const std::string SORT_BY_AGE = "6";
    const std::string SORT_BY_GENDER = "7";
    const std::string GO_BACK = "0";
    const std::string COMPUTER = "1";
    const std::string SCIENTIST = "2";
    const std::string SORT_BY_BUILDYEAR = "3";
    const std::string SORT_BY_DESIGNYEAR = "4";
    const std::string SORT_BY_TYPE = "5";
    const std::string MORE_INFO = "6";
    const std::string SEARCH_BY_TYPE = "1";
    const std::string SEARCH_BY_YEAR = "2";
    const std::string ADD_COMPUTER = "1";
    const std::string ADD_COMPUTER_TYPE = "2";
    const std::string COMPUTERS_SCIENTIST_CONTRIBUTED_TO = "8";
    const std::string COMPUTER_TRASH = "5";
    const std::string SCIENTIST_TRASH = "6";



}

#endif // CONSTANTS_H

