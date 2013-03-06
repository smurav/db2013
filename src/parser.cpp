#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian"); 
    
    ifstream file ("mephi.xml");
    string level;
    int length = -1;
    string word;
    string idword;
    string idwordto;
    string name;
    string text;
    bool label;
    bool label2 = false;
//    bool use_name;
    file >> word;
    do 
    {
         text = text + " ";
         text = text + word;
         file >> word;
    } while (!(file.eof()));
    
    for (int i=1; i <= text.length(); i++)
    {   
        if (text[i] == ' ') i++;
        if (text[i+1] == '?') 
                    {
                           i++;
                           while(text[i] != '?') i++;
                    };
        if (text[i] == '<') 
        {
                    i++;
                    
                    if (text[i] == ' ') i++;
                    if (text[i] != '/') length++;
                    else length--;
                    if (label2) length--;
                    label2 = false;
                    do
                    {
                            if ((text[i] == ' ') || (text[i] == '/'))  i++;
                            else 
                            {
                                 do  
                                 {
                                     idword = idword + text[i];
                                     i++;
                                 } while (text[i] != ' ');
                            };
                            i++;
                    } while (text[i] == ' ');
        };
        
        
            if (idword != "")  
            {
                 name = "";      
                 do 
                 {   
                    label = false;
                    i++;
                    if (text[i] == ' ') i++;
                    else 
                    {
                       do
                       {
                                         if ((text[i] == '"') && !label)
                                         {
                                                      label = true;
                                                      i++;             
                                         }
                                         else if ((text[i] != '"') && label)
                                         {
                                                      name = name + text[i];
                                                      i++;
                                         } 
                                         else if ((text[i] == '<') || (text[i] == '>')) break;
                                         else i++; 
                       } while ((text[i] != '"') || !(label));
                       if (text[i+1] == ' ')
                       {
                                     i++;
                       }
                       label = false;
                       name = name + " ";
                       if ((text[i+1] == '<') || (text[i+1] == '>')) break;
                    };
                    if ((text[i+1] == '/')&&(text[i+2] == '>'))
                    {
                         label2 = true;
                         break;
                    };
                 }while (text[i] != '<');   
                 
            
                 if (length > 0) 
                 {
                            for (int m = 0; m < length; m++) 
                            {
                                level = level + "      ";
                            };
                 };
                  
                 cout << level << idword << ": " << name << "\n";
                 level = "";
                 name = "";
                 idwordto = idword;
                 idword = "";
            };
            
    };    
                                                  

    
    system ( "PAUSE");
}
