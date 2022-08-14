#include "SymbolTable.h"

void SymbolTable::run(string filename)
{
    ifstream ifs(filename);
    string s;
    int begin = 0;
    while (!ifs.eof())
    {
        string p;
        getline(ifs, s);
        int x = s.length();
        for (int i = 0; i < x; i++)
        {
            p += s[i];
            if (s[i + 1] == ' ' || x == i + 1)
            {
                if (p == "INSERT")
                {
tryAgain:
                    p = "";
                    i += 2;
                    for (; i < x; i++)
                    {
                        p += s[i];
                        if (s[i + 1] == ' ')
                        {
                            i+=2;
                            string p3;
                            bool bo = false;
                            for(; i<x; i++)
                            {
                                if(s[i] == ' ')
                                {
                                    bo = true;
                                    i--;
                                    break;
                                }
                                p3+=s[i];
                            }
                            if(p3!="string"&&p3!="number")
                            {
                                InvalidInstruction error("INSERT " + p + " " + p3);
                                throw error;
                            }
                            if(p[0]>='a'&&p[0]<='z')
                            {
                                for(size_t ii = 1; ii<p.length(); ii++)
                                {
                                    if((p[ii]<'A'||p[ii]>'Z')&& (p[ii]<'a'||p[ii]>'z')&&(p[ii]<'0'||p[ii]>'9')&&p[ii]!='_')
                                    {
                                        InvalidInstruction error("INSERT " + p +" " + p3);
                                        throw error;
                                    }
                                }
                            }
                            else
                            {
                                InvalidInstruction error("INSERT " + p +" " + p3);
                                throw error;
                            }
                            bool check = true;
                            for (Node *k = this->head; k != NULL; k = k->next)
                            {
                                if (p == k->identifier_name && begin == k->STT)
                                {
                                    Redeclared error("INSERT " + p+ " " + p3);
                                    throw error;
                                }
                                else if (p == k->identifier_name && begin != k->STT)
                                {
                                    check = false;
                                    k->STT = begin;
                                    k->type =  p3;
                                    cout << "success" << endl;
                                    break;
                                }
                            }
                            if(check)
                            {
                                Node *N = new Node(p,p3,begin);
                                if(this->count==0)
                                {
                                    this->head = N;
                                    this->tail = N;
                                    this->count++;
                                }
                                else
                                {
                                    tail->next = N;
                                    N ->prev = tail;
                                    this->tail=N;
                                    this->count++;
                                }
                                cout << "success" << endl;
                            }
                            if(bo)
                            {
                                goto tryAgain;
                            }
                        }
                    }
                }
                else if(p=="ASSIGN")
                {
tryAgain1:
                    p="";
                    i+=2;
                    for(; i<x; i++)
                    {
                        p+=s[i];
                        if(s[i+1]==' ')
                        {
                            i+=2;
                            string p3;
                            bool bo = false;
                            if(s[i]=='\'')
                            {
                                p3+=s[i];
                                for(i = i+1; i<x; i++)
                                {
                                    p3+=s[i];
                                    if((s[i] == '\''&&s[i+1]!= '\''))
                                    {
                                        if(s[i+1] == ' ')
                                        {
                                            bo = true;
                                            break;
                                        }
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                for(; i<x; i++)
                                {
                                    if(s[i] == ' ')
                                    {
                                        bo = true;
                                        i--;
                                        break;
                                    }
                                    p3+=s[i];
                                }
                            }
                            if(p[0]>='a'&&p[0]<='z')
                            {
                                for(size_t ii = 1; ii<p.length(); ii++)
                                {
                                    if((p[ii]<'A'||p[ii]>'Z')&& (p[ii]<'a'||p[ii]>'z')&&(p[ii]<'0'||p[ii]>'9')&&p[ii]!='_')
                                    {
                                        InvalidInstruction error("ASSIGN "+p + " " + p3);
                                        throw error;
                                    }
                                }
                            }
                            else
                            {
                                InvalidInstruction error("ASSIGN "+p + " " + p3);
                                throw error;
                            }
                            bool check = true;
                            for(Node* k = this->head; k!=NULL; k=k->next)
                            {
                                if(p==k->identifier_name)
                                {
                                    check = false;
                                    if(k->type=="string")
                                    {
                                        if(p3[0]=='\'')
                                        {
                                            if(p3[p3.length()-1]!='\'')
                                            {
                                                InvalidInstruction error("ASSIGN " +p + " " + p3);
                                                throw error;
                                            }
                                            for(size_t j = 1; j<p3.length()-1; j++)
                                            {
                                                if(p3[j]!=' '&& (p3[j]<'A'||p3[j]>'Z')&& (p3[j]<'a'||p3[j]>'z')&&(p3[j]<'0'||p3[j]>'9'))
                                                {
                                                    InvalidInstruction error("ASSIGN "+p + " " + p3);
                                                    throw error;
                                                }
                                            }
                                            cout<<"success"<<endl;
                                            if(bo)
                                            {
                                                goto tryAgain1;
                                            }
                                        }
                                        else
                                        {
                                            bool check2 = true;
                                            if(p3[0]>='a'&&p3[0]<='z')
                                            {
                                                for(size_t ii = 1; ii<p3.length(); ii++)
                                                {
                                                    if((p3[ii]<'A'||p3[ii]>'Z')&& (p3[ii]<'a'||p3[ii]>'z')&&(p3[ii]<'0'||p3[ii]>'9')&&p3[ii]!='_')
                                                    {
                                                        InvalidInstruction error("INSERT " + p +" " + p3);
                                                        throw error;
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                for(size_t j = 0; j<p3.length(); j++)
                                                {
                                                    if(p3[j]<'0'||p3[j]>'9')
                                                    {
                                                        InvalidInstruction error("ASSIGN " + p + " " + p3);
                                                        throw error;
                                                    }
                                                }
                                                check2 = false;
                                            }
                                            if(check2){
                                            for(Node* k = this->head; k!=NULL; k=k->next)
                                            {
                                                if(k->identifier_name == p3 && k->type == "string")
                                                {
                                                    cout<<"success"<<endl;
                                                    if(bo)
                                                    {
                                                        goto tryAgain1;
                                                    }
                                                    break;
                                                }
                                                else if(k->identifier_name == p3 && k->type == "number")
                                                {
                                                    TypeMismatch error("ASSIGN " + p + " " + p3);
                                                    throw error;
                                                }
                                                if(k->next == NULL)
                                                {
                                                    Undeclared error("ASSIGN " + p + " " + p3);
                                                        throw error;
                                                }
                                            }
                                            }
                                            else{
                                            TypeMismatch error("ASSIGN " + p + " " + p3);
                                                    throw error;
                                            }

                                        }
                                    }
                                    else
                                    {
                                        bool check2 = true;
                                        if(p3[0]!='\'')
                                        {
                                            if(p3[0]>='a'&&p3[0]<='z')
                                            {
                                                for(size_t ii = 1; ii<p3.length(); ii++)
                                                {
                                                    if((p3[ii]<'A'||p3[ii]>'Z')&& (p3[ii]<'a'||p3[ii]>'z')&&(p3[ii]<'0'||p3[ii]>'9')&&p3[ii]!='_')
                                                    {
                                                        InvalidInstruction error("ASSIGN "+p + " " + p3);
                                                        throw error;
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                for(size_t j = 0; j<p3.length(); j++)
                                                {
                                                    if(p3[j]<'0'||p3[j]>'9')
                                                    {
                                                        InvalidInstruction error("ASSIGN " + p + " " + p3);
                                                        throw error;
                                                    }
                                                }
                                                check2 = false;
                                            }
                                            if(check2)
                                            {
                                                for(Node* k = this->head; k!=NULL; k=k->next)
                                                {
                                                    if(k->identifier_name == p3 && k->type == "number")
                                                    {

                                                        break;
                                                    }
                                                    else if(k->identifier_name == p3 && k->type == "string")
                                                    {
                                                        TypeMismatch error("ASSIGN " + p + " " + p3);
                                                        throw error;
                                                    }
                                                    if(k->next == NULL)
                                                    {
                                                        Undeclared error("ASSIGN " + p + " " + p3);
                                                        throw error;
                                                    }
                                                }
                                            }
                                            cout<<"success"<<endl;
                                            if(bo)
                                            {
                                                goto tryAgain1;
                                            }
                                            break;
                                        }
                                        else
                                        {
                                            if(p3[p3.length()-1]!='\'')
                                            {
                                                InvalidInstruction error("ASSIGN " + p + " " + p3);
                                                throw error;
                                            }
                                            for(size_t j = 1; j < p3.length()-1; j++)
                                            {
                                                if(p3[j]!=' '&& (p3[j]<'A'||p3[j]>'Z')&& (p3[j]<'a'||p3[j]>'z')&&(p3[j]<'0'||p3[j]>'9'))
                                                {
                                                    InvalidInstruction error("ASSIGN "+p + " " + p3);
                                                    throw error;
                                                }
                                            }
                                            TypeMismatch error("ASSIGN " + p + " " + p3);
                                            throw error;
                                        }
                                    }
                                    break;
                                }
                            }
                            if(check)
                            {
                                Undeclared error("ASSIGN "+p + " " + p3);
                                throw error;
                            }

                        }
                    }
                }
                else if(p=="BEGIN")
                {
                    begin++;
                }
                else if(p=="END")
                {
                    begin--;
                }
                else if(p=="PRINT")
                {
                    string s="";
                    for(int i=0; i<=begin; i++)
                    {
                        for(Node* k = head; k!=NULL; k=k->next)
                        {
                            if(i==k->STT)
                            {
                                s += k->identifier_name+"//"+to_string(k->STT)+" ";
                            }
                        }
                    }
                    if(s.length()>0)
                    {
                        s.erase(s.length()-1);
                        cout<<s<<endl;
                    }
                }
                else if(p=="RPRINT")
                {
                    string s;
                    for(int i=begin; i>=0; i--)
                    {
                        for(Node* k = tail; k!=NULL; k=k->prev)
                        {
                            if(i==k->STT)
                            {
                                s+=k->identifier_name+"//"+to_string(k->STT)+" ";
                            }
                        }
                    }
                    if(s.length()>0)
                    {
                        s.erase(s.length()-1);
                        cout<<s<<endl;
                    }
                }
                else if(p=="LOOKUP")
                {
tryAgain2:
                    p="";
                    i+=2;
                    bool bo = false;
                    for(; i<x; i++)
                    {
                        if(s[i]==' ')
                        {
                            bo = true;
                            i--;
                            break;
                        }
                        p+=s[i];
                    }
                    if(p[0]>='a'&&p[0]<='z')
                    {
                        for(size_t ii = 1; ii<p.length(); ii++)
                        {
                            if((p[ii]<'A'||p[ii]>'Z')&& (p[ii]<'a'||p[ii]>'z')&&(p[ii]<'0'||p[ii]>'9')&&p[ii]!='_')
                            {
                                InvalidInstruction error("LOOKUP "+ p);
                                throw error;
                            }
                        }
                    }
                    bool check = true;
                    for(Node* k = head; k!=NULL; k=k->next)
                    {
                        if(p==k->identifier_name&&k->STT<=begin)
                        {
                            check = false;
                            cout<<k->STT<<endl;
                        }
                    }
                    if(check)
                    {
                        Undeclared error("LOOKUP "+ p);
                        throw error;
                    }
                    if(bo)
                    {
                        goto tryAgain2;
                    }
                }
            }
        }
    }
    if(begin!=0)
    {
        if(begin>0)
        {
            UnclosedBlock error(begin);
            throw error;
        }
        else
        {
            UnknownBlock error;
            throw error;
        }
    }
    for(int i = 0;i<this->count;i++){
      Node* p = head;
      head = head->next;
      delete p;
    }
}
