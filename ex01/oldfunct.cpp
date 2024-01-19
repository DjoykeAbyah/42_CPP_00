// /**
//  * searches a contact based on index number of phonebook
//  */ 
// void PhoneBook::searchContact()
// {
//     std::string pageNum;
    
//     displayContacts();
//     std::cout << "\nWhich page do you want to see?\nplease give a number 1 - 8\n\n";
//     std::cin >> pageNum;
//     if (!isNumeric(pageNum))
//         std::cout << "\nPlease enter a numeric character from 1 till 8\n\n";
//     else
//     {
//         int number = std::stoi(pageNum);
//         printContact(number);
//     }
// }