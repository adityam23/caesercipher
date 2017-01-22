#include<iostream>
#include<sstream>//for stringstream
using namespace std;

int errMessages(int argc)
{
    if(argc<2)
        cout<<" Incorrect usage \n"
              " Use as follows :  <shift> <operation> <message>\n";
    else if(argc<4)
        cout<<" Not enough parameters \n"
              " Use as follows :  <shift> <operation> <message>\n";
    return 1;
}

void encryptMessage(string message, int key)
{
    string clearText;
    clearText.resize(message.length()); //empty string objects cannot be extended otherwise
    for(unsigned int i=0; i<(message.length()); i++)
    {
        if(isalpha(message[i]))
        {
            if(islower(message[i]))
                clearText[i] = (message[i] + key - 'a') % 26 + 'a';
            else
                clearText[i] = (message[i] + key - 'A') % 26 + 'A';
        }
        else clearText[i] = message[i];
    }
    cout<<" The encrypted message is : "<<clearText<<endl;
}

void decryptMessage(string message, int key)
{
    string clearText;
    clearText.resize(message.length()); //empty string objects cannot be extended otherwise
    for(unsigned int i=0; i<(message.length()); i++)
    {
        if(isalpha(message[i]))
        {
            if(islower(message[i]))
                clearText[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
            else
                clearText[i] = (message[i] - 'a' - key + 26) % 26 + 'A';
        }
        else clearText[i] = message[i];
    }
    cout<<" The encrypted message is : "<<clearText<<endl;
}

int main( int argc, char * argv[] )
{
    int er = 0;
    er = errMessages(argc);
    if(er)
        return 1;
    int shift = 0;
    stringstream converter(argv[1]);
    if(!(converter>>shift))
    {
        std::cout<<"Failed to convert to integer ! "
                    " Try again ";
    }
    string operation(argv[2]);
    string message(argv[3]);
    int i = 4;
    while(i < argc)
    {
        message+=argv[i];
        message+=" ";
        i++;
    }
    if(operation=="decrypt")
        decryptMessage(message, shift);
    else if(operation=="encrypt")
        encryptMessage(message, shift);
    else cout<<" Use as follows :  <shift> <operation> <message>\n";
    return 0;
}
