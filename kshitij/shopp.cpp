#include<iostream>
#include<string>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<cmath>

using namespace std;

class Node {
public:
    string itemname;
    int quantity;
    float price;
    int data;
    Node* next;
};

class Electroshop{
public:
    Node* head;
    Node* list;

public:
    Electroshop() : head(nullptr), list(nullptr) {}


    void insertfirst(int data, string itemname, int quantity, float price);
    void insertend(int data, string itemname, int quantity, float price);
    void updateitem(int udata, int uquantity);
    void itemslist();
    void main_menu();
    void deleteitem(int serial);
    void cls();
    void echo(string print);
    void welcome();

};


int main() {
    system("title CPP PROJECT - ELECTROSTOP");
    Electroshop e;
    e.welcome();
    Sleep(300);
    e.cls();

    int c = 0;
    int any;
    int cardno[100];
    float cardmoney[100];
    float totalmoney = 0;
    int total_order[100];
    int order_quantity[100];
    int order = 0;
    int uquantity;

    e.head = NULL;
    e.insertfirst(1, "PowerBank   ", 193, 1200);
    e.insertend(2, "Headphone   ", 175, 2500);
    e.insertend(3, "Speaker     ", 168, 2423.5);
    e.insertend(4, "USB Cable   ", 170, 400);
    e.insertend(5, "Pen Drive   ", 180, 525);
    e.insertend(6, "Home Theater", 139, 1999.99);
    e.insertend(7, "OTG Cable   ", 187, 1200);
    e.insertend(8, "4K LED TV   ", 173, 12499);
    e.insertend(9, "Fitness Band", 121, 1999);
    e.insertend(10, "BT Mouse    ", 180, 649);
    e.insertend(11, "Printer     ", 100, 8499);

mainmenu:
    e.main_menu();
    int main_menu_choice;
    cout<<"\n\nEnter your choice= ";
    cin >> main_menu_choice;

    if ((main_menu_choice >= 1 && main_menu_choice <= 3)) {
        if (main_menu_choice == 1) {
        itemslist:
            e.cls();
            cout << "=> 0. Main Menu ";
            e.itemslist();
        }
        else if (main_menu_choice == 2) {
        adminpanelchoice:
            int admin_panel_choice;
            e.cls();
            ;

            cout << "\n 1.Main Menu\n\n\t";
            Sleep(300);
            cout << "\nPlease Enter Password or ( 1 to Back in Main Menu ) : ";

            cin >> admin_panel_choice;

            if (admin_panel_choice == 12345) {///admin password is 12345
                Node* temp;
                temp = e.list;
            adminchoise:
                e.cls();


                e.echo("You are on Admin Pannel\n\n");

                cout << " 1. Total Cash Today \n\n";
                Sleep(250);
                cout << " 2. View Card Pay. \n\n";
                Sleep(250);
                cout << " 3. Add Item \n\n";
                Sleep(250);
                cout << " 4. Delete Item \n\n";
                Sleep(250);
                cout << " 0. Main Menu ";
                Sleep(250);
                int adminchoise;
                cin >> adminchoise;
                if (adminchoise == 1) {
                    e.cls();
                    ;
                    cout << "\nTodays Total Cash :Rs. " << totalmoney <<"/-"<< endl;
                    Sleep(2000);
                    goto adminchoise;
                }
                else if (adminchoise == 2) {

                    if (c != 0) {
                        e.cls();
                        cout << "\n ____________________________" << endl;
                        cout << "\n|   Card NO.   |   Money Rs.   |" << endl;
                        cout << "\n------------------------------" << endl;

                        for (int z = 1; z <= c; z++) {

                            cout << "|  " << cardno[z] << "       | " <<"Rs."<< cardmoney[z] << " /-    |" << endl;
                            cout << "------------------------------" << endl;
                            Sleep(150);
                        }
                        Sleep(1500);
                    }
                    if (c == 0) {
                        e.cls();
                        ;
                        cout << "*****No Card History Found******" << endl;
                    }
                    Sleep(1500);
                    goto adminchoise;
                }

                else if (adminchoise == 3) {
                foodadd:
                    e.cls();
                    string ffoodname;
                    int fquantity;
                    int fdata;
                    float fprice;
                    int fposi;

                    cout << " \nEnter item Name :  ";
                    cin>> ffoodname;
                fquantity:
                    cout << " \nEnter item Quantity :  ";
                    cin >> fquantity;
                foodserial:
                    cout << " \nEnter item Serial :  ";
                    cin >> fdata;
                    Node* exist;
                    exist = e.list;
                    while (exist->data != fdata) {
                        if (exist->next == NULL) {
                            break;
                        }
                        exist = exist->next;
                    }
                    if (exist->data == fdata) {
                        e.cls();
                        cout << " \nItem Serial Already Exist, Please Re-Enter  ";
                        Sleep(2000);
                        goto foodserial;
                    }
                fprice:
                    cout << " \nEnter Item Price :  ";
                    cin >> fprice;
                    cout << "\nSubmitting your data";
                    for (int cs = 0; cs < 4; cs++) {
                        cout << " .";
                        Sleep(500);
                    }
                    e.insertend(fdata, ffoodname, fquantity, fprice);
                    cout << "\n***Adding Item  Successful...." << endl;
                    Sleep(2000);
                    goto adminchoise;

                }
                else if (adminchoise == 4) {

                    e.cls();
                    ;
                    cout << "\nEnter Serial No of the Item To Delete : ";
                fdelete:
                    int fdelete;
                    cin >> fdelete;
                    Node* temp;
                    temp = e.list;
                    while (temp->data != fdelete) {
                        temp = temp->next;
                    }
                    if (temp->data == fdelete) {
                        e.deleteitem(fdelete);
                    }
                    else {

                        cout << "\nPlease Enter Correct Number :  ";
                        Sleep(500);
                        goto fdelete;
                    }
                    goto adminchoise;
                }

                else if (adminchoise == 0) {

                    goto mainmenu;
                }
                else {
                    cout << "\nPlease Select from the list :  ";
                    Sleep(500);
                    goto adminchoise;
                }
            }
            else if (admin_panel_choice == 1) {
                goto mainmenu;
            }
            else if(admin_panel_choice!=12345){
                    e.cls();
                cout<<"Invalid password please re-enter the pin"<<endl;
                Sleep(1400);
                goto adminpanelchoice;
            }
            else {
                cout << "\nPlease Enter Correct Choice";
                goto adminpanelchoice;
            }
        }
        else if (main_menu_choice == 3) {
            e.cls();
            ;
            cout << "\nThank You For Using Our System \n\n\n\n\n\n\n\t\t\t\tCreated by - Kshitij Thorat\n\t\t\t\tPRN NO:RBT22CS093\n\n\n";
            Sleep(1000);
            exit(1);
        }
    }
    else {
        cout << "\nPlease Enter Correct Choice";
        Sleep(300);
        goto mainmenu;
    }
    int get_item_choice;
    cout << "\nPlace Your Order(enter item no.): ";
    cin >> get_item_choice;
    if (get_item_choice == 0) {
        goto mainmenu;
    }
    Node* temp;
    temp = e.list;
    while (temp->data != get_item_choice) {
        temp = temp->next;
        if (temp == NULL) {
            e.echo("\nPlease Choose From List ");
            Sleep(1000);
            goto itemslist;
        }
    }
    if (get_item_choice == temp->data) {
    fcquantity:
        cout << "\nEnter Item Quantity : ";
        int fcquantity;
        cin >> fcquantity;
        e.cls();
        if (fcquantity == 0) {
            e.cls();
            cout << "\nQuantity Can not be Zero ";
            Sleep(2000);
            e.cls();
            goto itemslist;
        }
        else if (fcquantity > temp->quantity) {
            e.cls();
            cout << "\nOut of Stock ! ";
            Sleep(2000);
            goto itemslist;
        }
        double finalcost;
        finalcost = temp->price*fcquantity*0.18+temp->price*fcquantity;
        cout <<"\nChoice of item : " << temp->itemname << "\n\t\t\nTotal price = Rs." << temp->price * fcquantity <<"\n\t\t\n***Total payable price[including GST]=Rs."
        <<finalcost<< endl;
        cout<<"\n\n\n_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*__*_*"<<endl;
        cout << "\n 1.Confirm to buy this \n\n";
        cout << "\n 2.Back To Item List  \n\t\t\t\t";
        cout<<"\n Enter your choice:";

    confirm:
        int confirm;
        fflush(stdin);

        cin >> confirm;
        if (confirm == 1) {
            cout<<"\n\n\n_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_"<<endl;
            cout<<"\n\nENTER THE MODE OF PAYMENT"<<endl;
           // cout<<"\n";
            cout << " \n\n1.Cash ";

            cout << " \n\n2.Credit/Debit Card\n\t\t\t\t";
            cout<<" \nMake your choice=  ";

        payment:

            int payment;
            fflush(stdin);
            cin >> payment;

            if (payment == 1) {
                totalmoney += temp->price * fcquantity;
                order++;
                total_order[order] = get_item_choice;
                order_quantity[order] = fcquantity;
                uquantity = temp->quantity - fcquantity;
                e.updateitem(get_item_choice, uquantity);
                e.cls();
                float chk,cp;
                cout<<"Total amount to be paid by customer : "<<finalcost;
                cout<<"\n\n\tEnter amount to pay in cash  : ";
                cin>>chk;
            reverify:
                if(chk<round(finalcost)){

                    cout<<"\n\n\tMore amount to be paid : "<<round(finalcost-chk)<<endl;
                    cout<<"\n\n\tPay remaining amount : ";
                    cin>>cp;
                    chk+=cp;
                    if(chk==round(finalcost)){
                        goto stepout;
                    }
                    else{
                        goto reverify;
                    }

                }
                else if(chk>round(finalcost)){


                    cout<<"\n\tYour Refund amount is: "<<chk-finalcost<<endl;
                    Sleep(3000);
                }
            stepout:
                e.cls();
                cout << "====>THANK YOU FOR SHOPPING<==== \n\n===>PLEASE VISIT AGAIN<===" << endl;

                cout << "\n\n\n***Item Ordered Successfully ...***" << endl;

                cout << "\n\n\n 1.Want to Buy Another Item ? ";

                cout << "\n\n\n 2.Back to Main Menu \n\t\t\t\t";
                cout<<"\n\n\nEnter your choice=";
            psmenu:
                int ps_menu;
                fflush(stdin);
                cin >> ps_menu;
                if (ps_menu == 1) {
                    goto itemslist;
                }
                else if (ps_menu == 2) {
                    goto mainmenu;
                }
                else {
                    ;

                    cout << "\nPlease select correct option : ";
                    goto psmenu;
                }

            }
            else if (payment == 2) {
                int card_number[100];
                c++;
                e.cls();
                cout << "\nEnter Your Card No : ";
                fflush(stdin);
                cin >> card_number[c];
                cardno[c] = card_number[c];
                int pin;

                cout << "\nEnter Your Card Pin [we never save your pin]  : ";
                fflush(stdin);
                cin >> pin;
                cardmoney[c] = temp->price * fcquantity;
                totalmoney += temp->price * fcquantity;
                order++;
                total_order[order] = get_item_choice;
                order_quantity[order] = fcquantity;
                uquantity = temp->quantity - fcquantity;
                e.updateitem(get_item_choice, uquantity);


                cout << "\n\nPayment Success..."<<endl;


                cout << "\n\n 1. Wanna Buy Another Item ? "<<endl;


                cout << "\n\n 2. Main Menu "<<endl;
                cout<<"\n\nEnter your choice= ";
            psmenu2:
                int ps_menu2;
                cin >> ps_menu2;
                if (ps_menu2 == 1) {
                    goto itemslist;
                }
                else if (ps_menu2 == 2) {
                    goto mainmenu;
                }
                else {
                    ;

                    cout << "\nPlease choose correct option : ";
                    goto psmenu2;
                }
            }
            else {
                ;

                cout << "\nPlease Choose from List : ";
                goto payment;
            }
        }
        else if (confirm == 2) {
            goto itemslist;
        }
        else {
            ;

            cout << "\nPlease Choose correct option : ";
            goto confirm;
        }  ///end confirm;
    }  ///end get food choice if line

    else {
        ;

        e.echo("\nPlease Choose correct option ");
        ;
        Sleep(300);
        goto itemslist;
    }  ///end get food choice
}

void Electroshop::cls() {
    system("cls");
}

void Electroshop::echo(string print) {
    cout << print;
}



void Electroshop::main_menu() {
    cls();
    echo("===> 1. Item List");
    cout<<"\n\n"<<endl;
    echo("===> 2. Admin Panel");
    cout<<"\n\n"<<endl;
    echo("===> 3. Exit");
     cout<<"\n\n"<<endl;
}

void Electroshop:: insertend(int data, string itemname, int quantity, float price) {
    Node* temp;
    temp = new Node;
    temp->data = data;
    temp->price = price;
    temp->quantity = quantity;
    temp->itemname = itemname;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        list = head;
    }
    else {
        while (head->next != NULL) {
            head = head->next;
        }
        head->next = temp;
    }
}

void Electroshop::insertfirst(int data, string itemname, int quantity, float price) {
    Node* temp;
    temp = new Node;
    temp->data = data;
    temp->price = price;
    temp->itemname = itemname;
    temp->quantity = quantity;
    temp->next = head;
    head = temp;
    list = head;
}

void Electroshop::deleteitem(int serial) {

    Node* temp;
    temp = new Node;

    temp = list;


    if (temp->data != serial) {

        while (temp->next->data != serial) {
            temp = temp->next;
        }

        if (temp->next->data == serial) {

            temp->next = temp->next->next;
            cls();
            cout << "\n\n\n\n\t\t\tDeleting Item " << serial;
            for (int cs = 0; cs < 4; cs++) {
                cout << " .";
                Sleep(400);
            }

            cout << "\n\n\n\n\t\t\tDeleted Successfully \n";
            Sleep(500);

        }
        else {
            cout << "\n\n\n\n\t\t\t Item Not Found\n";
            Sleep(500);
        }

        head = temp;

    }
    else {

        temp = temp->next;
        cls();
        cout << "\n\n\n\n\t\t\tDeleting Item " << serial;
        for (int cs = 0; cs < 4; cs++) {
            cout << " .";
            Sleep(400);
        }

        cout << "\n\n\n\n\t\t\tDeleted Successfully \n";
        Sleep(500);

        head = temp;

        list = head;
    }
}

void Electroshop::updateitem(int udata, int uquantity) {
    Node* temp;
    temp = list;
    while (temp->data != udata) {
        temp = temp->next;
    }
    if (temp->data == udata) {
        temp->quantity = uquantity;
    }
}

void Electroshop::itemslist() {

    cout << "\n\t\t";
    cout << "_____________________________________________________________" << endl;
    cout << "\n\t\t";
    cout << "|  Item No.  |   Item Name       |  Price       |    In Stock   |" << endl;
    cout << "\n\t\t";
    cout << "-------------------------------------------------------------" << endl;
    Node* temp;
    temp = list;
    while (temp != NULL) {
        cout << "\n\t\t";
        cout << "|     " << temp->data << "      |    " << temp->itemname << "   |     " << temp->price << "   |     " << temp->quantity << "    |" << endl;
        cout << "\n\t\t";
        cout << "--------------------------------------------------------------" << endl;
        temp = temp->next;
    }
    //  free(temp);
}

void Electroshop::welcome() {
    cout << "\n\n\n\n\n\n";
    cout << "\t\t WELCOME \n\n\t\t TO\n\n\t\t 'ELECTROSTOP'\n\n\t\t ONLINE\n\n\t\t SHOPPING\n\n\t\t SYSTEM\n";
    Sleep(2000);
}
