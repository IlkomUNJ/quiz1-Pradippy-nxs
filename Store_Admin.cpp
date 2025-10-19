#include "Store.h"
#include "Timer.h" 
#include <iostream>

void Store::showBankMenu()
{
    cout << "\n--- Bank Admin Menu ---" << endl;
    cout << "1. List All Customers\n2. List Inactive Accounts\n0. Back" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        for (int i = 0; i < allAccounts.size(); i++)
        {
            cout << "User: " << allAccounts[i]->ownerUsername << ", Balance: $" << allAccounts[i]->balance << endl;
        }
    }
    else if (choice == 2)
    {
        cout << "--- Inactive Accounts (no Transaction in 1 month) ---" << endl;
        for (int i = 0; i < allAccounts.size(); i++)
        {
            bool hasRecentTransaction = false;
            for (int j = 0; j < allTransactions.size(); j++)
            {
                if (allTransactions[j]->buyerUsername == allAccounts[i]->ownerUsername)
                {
                    if (TimeUtil::isLastMonth(allTransactions[j]->timestamp))
                    {
                        hasRecentTransaction = true;
                        break;
                    }
                }
            }
            if (!hasRecentTransaction)
            {
                cout << allAccounts[i]->ownerUsername << " is Inactive." << endl;
            }
        }
    }
}

void Store::showStoreMenu()
{
    cout << "\n--- Store Admin Menu ---" << endl;
    cout << "1. List All Transactions\n2. List Paid but not Completed\n0. Back" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        for (int i = 0; i < allTransactions.size(); i++)
        {
            cout << "Type: " << allTransactions[i]->type << ", Buyer: " << allTransactions[i]->buyerUsername << ", Amount: $" << allTransactions[i]->totalPrice << endl;
        }
    }
    else if (choice == 2)
    {
        for (int i = 0; i < allTransactions.size(); i++)
        {
            if (allTransactions[i]->status == "paid")
            {
                cout << "Item: " << allTransactions[i]->itemName << ", Buyer: " << allTransactions[i]->buyerUsername << endl;
            }
        }
    }
}