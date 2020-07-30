#include "Store.h"
#include "Customer.h"
#include "Product.h"

using namespace std;

int main() {

/***************test for product***************/
//     cout << "/***************test for product***************/" << endl;
//     Product p1 = Product(001,"A");
//     Product p2 = Product(002,"C");

//     //basic test for p1
//     cout << "ID: " << p1.getID() << endl;
//     cout << "ProductName: " << p1.getName() << endl;
//     p1.addShipment(500, 2000); 
//     // 500 items that cost a total of $2000
//     cout << "Price of p1 after change: " << p1.getPrice() << endl;
//     p2.addShipment(200, 1000);
//     // 200 items that cost a total of $1000
//     cout << "Price of p2: " << p2.getPrice() << endl;
//     cout << "Getting total paid of p1... : " << p1.getTotalPaid() << endl;
//     // reduce 100 items
//     cout << "Inventory of p1: " << p1.getInventoryCount() << endl;
//     p1.reduceInventory(100);
//     cout << "Getting inventory count after reduce 100 for p1... : " << p1.getInventoryCount() << endl;

//     cout << "p1 info: " << p1;

// //     //try error
// //     //p1.addShipment(-5, 200);

//     //other test for p2
//     cout << "ProductName(before change): " << p2.getName() << endl;
//     p2.setName("B");
//     cout << "ProductName(after change): " << p2.getName() << endl;

//     cout << "ProductDescription(before set): " << p2.getDescription() << endl;
//     p2.setDescription("Very good.");
//     cout << "ProductDescription(after set): " << p2.getDescription() << endl;

// //     //try error
// //     //p2.setName("");

// //     //test for '<<' operator
// //     //cout << "getting info for p2...\n" << p2;

// /***************test for customer***************/
//     cout << "/***************test for customer***************/" << endl;
//     Customer c1 = Customer(01,"AA");
//     Customer c2 = Customer(02,"CC");

//     //basic test for c1
//     cout << "ID: " << c1.getID() << endl;
//     cout << "CustomerName: " << c1.getName() << endl;
//     cout << "Getting credit... : " << c1.getCredit() << endl;    

//     //other test for c2
//     cout << "CustomerName(before change): " << c2.getName() << endl;
//     c2.setName("BB");
//     cout << "CustomerName(after change): " << c2.getName() << endl;
//     cout << "Getting credit(before change)... : " << c2.getCredit() << endl;
//     c2.setCredit(true);
//     cout << "Getting credit(after change)... : " << c2.getCredit() << endl;

//     //test for balance
//     c1.processPayment(100);
//     c2.processPayment(100);

//     c1.processPurchase(20,p1);
//     c1.processPurchase(20,p2);

//     c2.processPurchase(100,p1);
//     c2.processPurchase(10,p2);

//     cout << "c2 info: " << endl << c2;

//     cout << c1.getName() << "purchased: " << endl;
//     cout << c1.getProductsPurchased();

//     //cout << "get info of customer " << c2.getName() << ": " << endl;
//     //cout << c2;

// /***************test for store***************/
//     cout << "/***************test for store***************/" << endl;
//     Store s1 = Store("store A");
//     Store s2 = Store();
//     cout << "StoreName(before change): " << s2.getName() << endl;
//     s2.setName("store B");
//     cout << "StoreName(after change): " << s2.getName() << endl;

//     s1.addProduct(111, "Hat");
//     s1.addProduct(222, "T-shirt");
//     // s1.addProduct(333, "Shoe");

//     s1.addCustomer(001, "Abby", true);
//     s1.addCustomer(002, "Barbara");
//     s1.addCustomer(003, "Cindy");

//     s1.takeShipment(111, 10, 200);
//     s1.takeShipment(222, 20, 200);

//     s1.sellProduct(001, 111, 3);
//     s1.sellProduct(001, 222, 5);

//     cout << s1.listCustomers();
//     cout << s1.listProducts();

/***************test for Mimir***************/
    cout << "/***************test for Mimir***************/" << endl;

    //basic of product
    Product p(123, "Clueless");
    p.setDescription("This does some fun stuff.");
    p.addShipment(155, 1317.5);
    cout << p.getTotalPaid() << endl; //1317.5
    cout << p.getInventoryCount() << endl; //155
    cout << p.getNumberSold() << endl; //0
    cout << p.getPrice() << endl; //10.625


    cout << p.getTotalPaid() << endl; //1317.5
    cout << p.getInventoryCount() << endl; //155
    cout << p.getNumberSold() << endl; //0
    cout << p.getPrice() << endl; //10.625

    p.addShipment(200, 500);
    cout << p.getTotalPaid() << endl; //1817.5
    cout << p.getInventoryCount() << endl; //355
    cout << p.getNumberSold() << endl; //0
    cout << p.getPrice() << endl; //6.39965

    Store s;
   
    cout << s.getName(); //,"");
  
    s.addProduct(123,"towel");
    s.getProduct(123).setDescription("For drying.");

    cout << s.getProduct(123).getID(); //,123);
    cout << s.getProduct(123).getName(); //,"towel");
    cout << s.getProduct(123).getInventoryCount() << endl; //,0);
    cout << s.getProduct(123).getTotalPaid() << endl; //,0.0);
    cout << s.getProduct(123).getNumberSold() << endl; //, 0);
    cout << s.getProduct(123).getDescription() << endl; //,"For drying.");
    // s.addProduct(123,"random");

    s.addProduct(234,"mask");
    s.getProduct(234).setDescription("For hiding.");
    cout << s.getProduct(234).getID() << endl; //,234);
    cout << s.getProduct(234).getName() << endl; //,"mask");
    cout << s.getProduct(234).getInventoryCount() << endl; //,0);
    cout << s.getProduct(234).getTotalPaid() << endl; //,0.0);
    cout << s.getProduct(234).getNumberSold() << endl; //, 0);
    cout << s.getProduct(234).getDescription() << endl; //,"For hiding.");

    // s.addProduct(123,"random"); //,std::runtime_error);

    // cout << s.getProduct(555); //,std::runtime_error);
    s.takeShipment(123,200,400);
    s.takeShipment(234,200,400);

    s.addCustomer(987,"Joe Blockhead",true);

    s.takePayment(987,600);


    cout << s.getCustomer(987).getID() << endl;//,987);
    cout << s.getCustomer(987).getName() << endl;//,"Joe Blockhead");
    cout << s.getCustomer(987).getCredit() << endl;//,true);
    cout << s.getCustomer(987).getBalance() << endl;//,600,.001);
    cout << s.getCustomer(987).getProductsPurchased() << endl;//,"");

    s.sellProduct(987,123,10);
    s.sellProduct(987,234,10);

    cout << s.listProducts();
    cout << s.listCustomers();

	return 0;
}