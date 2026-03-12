#ifndef ATM_H
#define ATM_H

#include <iostream>
#include <string>

using namespace std;

extern string AccountType[];
extern int AccountDetails[];

bool validatePin(int pin);
void menu();

class Account
{
protected:
    int balance;

public:
    Account(int b);
    virtual void showBalance() = 0;
    virtual void withdraw(int amount) = 0;
    virtual void deposit(int amount) = 0;
    virtual ~Account();
};

class Checkings : public Account
{
public:
    Checkings();
    void showBalance();
    void withdraw(int amount);
    void deposit(int amount);
};

class Savings : public Account
{
public:
    Savings();
    void showBalance();
    void withdraw(int amount);
    void deposit(int amount);
};

void accountMenu(Account* acc);

#endif
#pragma once
#pragma once
