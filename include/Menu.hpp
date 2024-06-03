#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include "HashTable.hpp"
#include "OpenAddressingTable.hpp"
#include "ClosedAddressigTable.hpp"
#include "Avl.hpp"
#include "CuckooHashingTable.hpp"


class Menu
{
protected:
      int userChoice = 0;
public:
      virtual void display() const;
      virtual void run();
};

template <typename T>
class HashTableMenu : public Menu
{
protected: 
      std::unique_ptr<HashTable<T>> ht;
      const int exitOption = 4;
public:
      void display() const override;
      void run() override;
};

template <typename T>
class OperationMenu : public Menu
{
protected:
      std:unique_ptr<HashTable<T>> ht;
      const int exitOption = 3;
};

class DataTypeMenu : public Menu
{
public:
    void display() const override;
    void run() override;
};


//Hash Table Menu

template <typename T>
void HashTableMenu<T>::display() const
{
      std::cout<<"------------------- Menu ------------------"<<std::endl;
      std::cout<<"1. Create an open addressing hash table"<<std::endl;
      std::cout<<"2. Create a closed addressing hash table"<<std::endl;
      std::cout<<"3. Create an AVL tree-based hash table"<<std::endl;
      std::cout<<"4. Create a Cuckoo hashing table"<<std::endl;
      std::cout<<"5. Exit program"<<std::endl;
      std::cout<<"--------------------------------------------"<<std::endl;
      std::cout<<"Choose one option from the menu:"<<std::endl;
}

template <typename T>
void HashTableMenu<T>::run()
{
      while ( userChoice != exitOption)
        {
            this->display();
            std::cin>>userChoice;

            switch(userChoice)
              {
                case 1:
                  {
                    //creating open adressing hash table
                  }

                case 2:
                  {
                    //creating closed adressing hash table
                  }

                case 3:
                  {
                    //creating AVL hash table
                  }

                case 4:
                  {
                    //create cuckoo hash table
                  }

                case 5:
                  {
                    exit(0);
                    break;
                  }

                default:
                  {
                    std::cerr<<"error: chosen option does not exist"<<std:endl;
                    exit(1);
                  }
              }
           std::cout << "Press enter to continue";

        // Wait for enter
        std::cin.get();
        std::cin.get();
        
        system("clear");

        OperationMenu<T> m1;
        m1.ht = std::move(ht);
        m1.run();
    }             
}



//Operation Menu

template <typename T>
void OperationMenu<T>::display() const
{
      std::cout<<"------ Operation Menu ------"<<std::endl;
      std::cout<<"1. Insert"<<std::endl;
      std::cout<<"2. Remove"<<std::endl;
      std::cout<<"3. Exit structure menu"<<std::endl;
      std::cout<<"----------------------------"<<std::endl;
      std::cout<<"Choose an operation to perform: "<<std::endl;
}

template <typename T>
void OperationMenu<T>::run()
{
      T key, value;
      while (userChoice != exitOption)
      {
        this->display();
        std::cin>>userChoice;

        switch (userChoice)
        {
            case 1:
            {
                std::cout<<"Enter key to be added: "<<std::endl;
                std::cin>>key;
                std::cout<<"Enter value: "<<std::endl;
                std::cin>>value;
                ht->insert(key, value);
                break;
            }
          
            case 2:
            {
                std::cout<<"Enter key to be removed: "<<std::endl;
                std::cin>>key;
                ht->remove(key);
                break;
            }
          
            case 3:
            {
                break;
            }
          
            default:
            {
                std::cerr<<"error: chosen option does not exist"<<std::endl;
                exit(1);
            }
        }

        std::cout<<"Press enter to continue"<<std::endl;

        // Wait for enter
        std::cin.get();
        std::cin.get();

        system("clear");
    }
}


//Data Type Menu

void DataTypeMenu::display() const
{
    std::cout<<"----------"<<std::endl;
    std::cout<<"1. Int"<<std::endl;
    std::cout<<"2. Float"<<std::endl
    std::cout<<"3. Char"<<std::endl
    std::cout<<"4. String"<<std::endl
    std::cout<<"----------"<<std::endl
    std::cout<<"Choose a data type to use with hash table: "<<std::endl
}

void DataTypeMenu::run()
{
    while (true)
    {
        this->display();
        std::cin>>userChoice;

        std::cout<<"Press enter to continue"<<std::endl;

        // Wait for enter
        std::cin.get();
        std::cin.get();

        system("clear");

        switch (userChoice)
        {
            case 1:
            {
                HashTableMenu<int> m1;
                m1.run();
                break;
            }
          
            case 2:
            {
                HashTableMenu<float> m2;
                m2.run();
                break;
            }
          
            case 3:
            {
                HashTableMenu<char> m3;
                m3.run();
                break;
            }
          
            case 4:
            {
                HashTableMenu<std::string> m4;
                m4.run();
                break;
            }
          
            default:
            {
                std::cerr<<"error: chosen option does not exist"<<std::endl;
                exit(1);
            }
        }
    }
}


#endif MENU_HPP
