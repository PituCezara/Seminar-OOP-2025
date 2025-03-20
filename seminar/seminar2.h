//
// Created by Cezara on 20.03.2025.
//
#include<string>
#include<iostream>
#include<cmath>
#ifndef SEMINAR2_H
#define SEMINAR2_H

class BankAccount {
private:
    std::string name;
    std::string iban;
    double balance;
public:
    BankAccount(std::string iban,std::string name) {
        this->iban = iban;
        this->name=name;
        this->balance = 0.0;

        std::cout<<"Bank account created: "<<iban<<std::endl;
    }
    BankAccount(std::string iban,std::string name, double balance) :
    BankAccount(iban,name){
        this->iban = iban;
        this->name = name;
        this->balance = balance;
    }

    bool deposit(double amount) {
        if (amount<0)
            return false;
        balance+=amount;
        return true;
    }
    ~BankAccount() {
        std::cout<<"Bank account destroyed: "<<iban<<std::endl;
    }
    std::string get_iban() {
        return iban;
    }
    double get_balance() {
        return balance;
    }

};

class Person {
private:
    std::string nume;
public:
    Person(BankAccount);
};



#endif //SEMINAR2_H