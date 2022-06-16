/*
Author: Xiaoyo
time: 2022/06/16
*/
#include "iostream"
#include "string"
#include "map"
#include "book.h"
using namespace std;

book::book() : bookName(""), authors(""), price(0){}
book::book(string BN, string AT, int _price){
    bookName = BN;
    authors = AT;
    price = _price;
}
void book::assign(string BN, string AT, int _price){
    bookName = BN;
    authors = AT;
    price = _price;
}
string book::getBN() { return bookName; }
string book::getAT() { return authors; }
int book::getPrice() { return price; }

int Lookuptable::add(book a){
    if(table.find(a.getBN()) != table.end()) return 0;
    table[a.getBN()] = a;
    return 1;
}
int Lookuptable::remove(book a){
    if(table.find(a.getBN()) == table.end()) return 0;
    table.erase(a.getBN());
    return 1;
}
book *Lookuptable::find(string BN){
    if(table.find(BN) == table.end()) return 0;
    return &table[BN];
}
void Lookuptable::clean(){
    table.clear();
}

void test(LookupTable *ptr){
    int i;
    book val, *vptr;
    cout << "Test LookupTable" << endl;
    cout << "Test add" << endl;

    val.assign("精通光學辨識技術:應用ABBYY FineReader 11 OCR", "黃敦義", 371);
    cout << ptr->add(val) << endl; //回傳成功(1)
    val.assign("VISUAL FORTRAN程式設計與開發", "張嘉強、陳鴻智", 400);
    cout << ptr->add(val) << endl; //回傳成功(1)
    val.assign("程式設計-使用C++", "黃建庭", 420);
    cout << ptr->add(val) << endl; //回傳成功(1)
    val.assign("資料庫系統-MTA認證影音教學", "李春雄", 336);
    cout << ptr->add(val) << endl; //回傳成功(1)
    val.assign("輕鬆搞定Google雲端技術:Maps.Android.App Engine.Cloud SQL與電子商務API實例解析", "陳世興", 560);
    cout << ptr->add(val) << endl; //回傳成功(1)
    val.assign("人工智慧：智慧型系統導論(第三版) ", "李聯旺 廖珗洲 謝政勳", 590);
    cout << ptr->add(val) << endl; //回傳成功(1)
    val.assign("電腦網路概論(第二版)", "陳雲龍", 420);
    cout << ptr->add(val) << endl; //回傳成功(1)
    val.assign("網際網路與電子商務(第三版)", "朱正忠", 450);
    cout << ptr->add(val) << endl; //回傳成功(1)
    val.assign("資料庫系統理論-使用SQL Server 2008", "李春雄", 650);
    cout << ptr->add(val) << endl; //回傳成功(1)
    val.assign("動畫圖解資料庫系統理論-使用Access 2010實作(第二版) ", "李春雄", 600);
    cout << ptr->add(val) << endl; //回傳成功(1)

    cout << "最貴的書: " << ptr->mostExpensive() << endl;
    //最貴的書: "資料庫系統理論－使用SQL Server 2008" "李春雄" 650
    cout << "最便宜的書: " << ptr->cheapest() << endl;
    //最便宜的書: "資料庫系統－MTA認證影音教學" "李春雄" 336
    cout << "平均書價格: " << ptr->average() << endl;
    //平均書價格: ...

    val.assign("精通光學辨識技術:應用ABBYY FineReader 11 OCR", "黃敦義", 371);
    cout << ptr->add(val) << endl; //失敗回傳0
    val.assign("VISUAL FORTRAN程式設計與開發", "張嘉強、陳鴻智", 400);
    cout << ptr->add(val) << endl; //失敗回傳0
    val.assign("程式設計-使用C++", "黃建庭", 420);
    cout << ptr->add(val) << endl; //失敗回傳0
    val.assign("資料庫系統-MTA認證影音教學", "李春雄", 336);
    cout << ptr->add(val) << endl; //失敗回傳0
    val.assign("輕鬆搞定Google雲端技術:Maps.Android.App Engine.Cloud SQL與電子商務API實例解析", "陳世興", 560);
    cout << ptr->add(val) << endl; //失敗回傳0
    val.assign("人工智慧：智慧型系統導論(第三版) ", "李聯旺 廖珗洲 謝政勳", 590);
    cout << ptr->add(val) << endl; //失敗回傳0
    val.assign("電腦網路概論(第二版)", "陳雲龍", 420);
    cout << ptr->add(val) << endl; //失敗回傳0
    val.assign("網際網路與電子商務(第三版)", "朱正忠", 450);
    cout << ptr->add(val) << endl; //失敗回傳0
    val.assign("資料庫系統理論-使用SQL Server 2008", "李春雄", 650);
    cout << ptr->add(val) << endl; //失敗回傳0
    val.assign("動畫圖解資料庫系統理論-使用Access 2010實作(第二版) ", "李春雄", 600);
    cout << ptr->add(val) << endl; //失敗回傳0

    cout << "最貴的書: " << ptr->mostExpensive() << endl;
    cout << "最便宜的書: " << ptr->cheapest() << endl;
    cout << "平均書價格: " << ptr->average() << endl;

    cout << "Test remove" << endl;

    if (ptr->remove("精通光學辨識技術:應用ABBYY FineReader 11 OCR", "黃敦義", 371))
        cout << "成功 " << val << endl;
    // 成功 "精通光學辨識技術：應用ABBYY FineReader 11 OCR" "黃敦義" 371
    else
        cout << "失敗" << endl; // 失敗

    if (ptr->remove("電腦網路概論(第二版)", "陳雲龍", 420))
        cout << "成功 " << val << endl;
    // 成功 "電腦網路概論(第二版)" "陳雲龍" 420
    else
        cout << "失敗" << endl; // 失敗

    if (ptr->remove("動畫圖解資料庫系統理論:使用Access 2010實作(第二版) ", "李春雄", 600))
        cout << "成功 " << val << endl;
    // 成功 ""動畫圖解資料庫系統理論－使用Access 2010實作(第二版)" "李春雄" 600
    else
        cout << "失敗" << endl; // 失敗

    if (ptr->remove("動畫圖解資料庫系統理論:使用Access 2010實作(第二版) ", "李春雄", 600))
        cout << "成功 " << val << endl;
    // 成功 ""動畫圖解資料庫系統理論－使用Access 2010實作(第二版)" "李春雄" 600
    else
        cout << "失敗" << endl; // 失敗

    cout << “Test find” << endl;

    if (vptr = ptr->find("精通光學辨識技術:應用ABBYY FineReader 11 OCR"))
        cout << "成功 " << *vptr << endl; // 成功
    else
        cout << "失敗" << endl; // 失敗
    if (vptr = ptr->find("電腦網路概論(第二版)"))
        cout << "成功 " << *vptr << endl; // 成功
    else
        cout << "失敗" << endl; // 失敗

    if (vptr = ptr->find("動畫圖解資料庫系統理論:使用Access 2010實作(第二版) "))
        cout << "成功 " << *vptr << endl; // 成功
    else
        cout << "失敗" << endl; // 失敗

    if (vptr = ptr->find("精通光學辨識技術:應用ABBYY FineReader 11 OCR", "黃敦義"))
        cout << "成功 " << *vptr << endl; // 成功
    else
        cout << "失敗" << endl; // 失敗

    if (vptr = ptr->find("電腦網路概論(第二版)", "陳雲龍"))
        cout << "成功 " << *vptr << endl; // 成功
    else
        cout << "失敗" << endl; // 失敗

    if (vptr = ptr->find("動畫圖解資料庫系統理論-使用Access 2010實作(第二版) ", "李春雄"))
        cout << "成功 " << *vptr << endl; // 成功
    else
        cout << "失敗" << endl; // 失敗

    cout << "最貴的書: " << ptr->mostExpensive() << endl;
    cout << "最便宜的書: " << ptr->cheapest() << endl;
    cout << "平均書價格 : " << ptr->average() << endl;

    cout << "Test clean" << endl;
    ptr->clean();

    if (ptr->remove("動畫圖解資料庫系統理論-使用Access 2010實作(第二版) ", "李春雄", 600))
        cout << "成功 " << val << endl;
    // 成功 ""動畫圖解資料庫系統理論－使用Access 2010實作(第二版)" "李春雄" 600
    else
        cout << "失敗" << endl; // 失敗

    if(vptr = ptr->find("精通光學辨識技術:應用ABBYY FineReader 11 OCR" ))
		cout << "成功 "<< *vptr << endl;  	   	// 成功  
    else
	    cout << "失敗" << endl;  	   		// 失敗
    if(vptr = ptr->find("精通光學辨識技術:應用ABBYY FineReader 11 OCR", "黃敦義"))
	    cout << "成功 "<< *vptr << endl;  	   	// 成功  
    else
		cout << "失敗" << endl;  	   		// 失敗

/////////////////////////////////////////////////////////////////////
// 壓力測試
/////////////////////////////////////////////////////////////////////

cout << "壓力測試" << endl;
srand ( time(NULL) );

cout << "Test add" << endl;
	char buffer [16];
	string str1("壓力測試"), str2;
	for(i = 0; i < 1000; i++){
        itoa(i, buffer, 10);
        str2 = str1 + buffer;
        val.assign(str2, str2, rand());
        ptr->add(val);	 	
	}

    cout << "Test find" << endl;
	for(i = 0; i < 1000; i++){
        itoa(i, buffer, 10);
        str2 = str1 + buffer;
        ptr->find(str2);		
	}

    cout << "Test find" << endl;
	for(i = 0; i < 1000; i++){
        itoa(i, buffer, 10);
        str2 = str1 + buffer;
        ptr->find(str2, str2);		
	}

    cout << "Test remove" << endl;
	for(i=0; i<1000; i++){
        itoa(i, buffer, 10);
        str2 = str1 + buffer;
        ptr->remove(str2, str2, val);
 	}
}

int main(){
    /*
    LookupTable *ptr;

// Adaptee 1
    ptr = new adapter_class_1;
    test(ptr);
    delete ptr;

    ptr = new adapter_object_1;
    test(ptr);
    delete ptr;

// Adaptee 2
    ptr = new adapter_class_2;
    test(ptr);
    delete ptr;

    ptr = new adapter_object_2;
    test(ptr);
    delete ptr;

// Adaptee 3
    ptr = new adapter_class_3;
    test(ptr);
    delete ptr;

    ptr = new adapter_object_3;
    test(ptr);
    delete ptr;
    */
}