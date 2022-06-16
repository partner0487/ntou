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

int sum = 0;
int total = 0;
book Expensive;
book Expensive2;
book cheap, cheap2;

int Lookuptable::add(book a){
    if(table.find(a.getBN()) != table.end()) return 0;
    if(a.getPrice() > Expensive.getPrice())
        Expensive2 = Expensive, Expensive = a;
    if(a.getPrice() < cheap.getPrice())
        cheap2 = cheap, cheap = a;
    table[a.getBN()] = a;
    total++;
    sum += a.getPrice();
    return 1;
}
int Lookuptable::remove(book a){
    if(table.find(a.getBN()) == table.end()) return 0;
    if(a.getBN() == Expensive.getBN()) Expensive = Expensive2;
    if(a.getBN() == cheap.getBN()) cheap = cheap2;
    table.erase(a.getBN());
    total--;
    sum -= a.getPrice();
    return 1;
}
book *Lookuptable::find(string BN){
    if(table.find(BN) == table.end()) return 0;
    return &table[BN];
}
void Lookuptable::clean(){
    table.clear();
    total = 0;
    book tmp;
    Expensive = tmp;
}
book Lookuptable::cheapest(){
    return cheap;
}
book Lookuptable::mostExpensive(){
    return Expensive;
}
double Lookuptable::average(){
    return (double)sum / (double)total;
}

void adaptee::add(book v, int &result){
    if(MB.find(v.getBN()) != MB.end()) result = 0;
    else{
        if(v.getPrice() > Expensive.getPrice())
            Expensive2 = Expensive, Expensive = v;
        if(v.getPrice() < cheap.getPrice())
            cheap2 = cheap, cheap = v;
        MB[v.getBN()] = v;
        total++;
        sum += v.getPrice();
        result = 1;
    }
}
void adaptee::remove(book v, int &result){
    if(MB.find(v.getBN()) == MB.end()) result = 0;
    else{
        if(v.getBN() == Expensive.getBN()) Expensive = Expensive2;
        if(v.getBN() == cheap.getBN()) cheap = cheap2;
        MB.erase(v.getBN());
        total--;
        sum -= v.getPrice();
        result = 1;
    }
}
void adaptee::find(string BN, book *&p){
    if(MB.find(BN) == MB.end()) p = nullptr;
    else p = &MB[BN];
}
void adaptee::clean(){
    MB.clear();
    book tmp;
    Expensive = tmp;
}
book adaptee::mostExpensive(){
    return Expensive;
}
book adaptee::cheapest(){
    return cheap;
}
double adaptee::average(){
    return (double)sum / (double)total;
}

int adapter_object_1::add(book a){
    int ret;
    ad.add(a, ret);
    return ret;
}
int adapter_object_1::remove(book a){
    int ret;
    ad.remove(a, ret);
    return ret;
}
book *adapter_object_1::find(string BN){
    book *p;
    ad.find(BN, p);
    return p;
}
void adapter_object_1::clean(){
    ad.clean();
}
book adapter_object_1::mostExpensive(){
    return ad.mostExpensive();
}
book adapter_object_1::cheapest(){
    return ad.cheapest();
}
double adapter_object_1::average(){
    return ad.average();
}

int adapter_class_1::add(book a){
    int ret = 0;
    adaptee::add(a, ret);
    return ret;
}
int adapter_class_1::remove(book a){
    int ret = 0;
    adaptee::remove(a, ret);
    return ret;
}
book *adapter_class_1::find(string BN){
    book *p;
    adaptee::find(BN, p);
    return p;
}
void adapter_class_1::clean(){
    adaptee::clean();
}
book adapter_class_1::mostExpensive(){
    return adaptee::mostExpensive();
}
book adapter_class_1::cheapest(){
    return adaptee::cheapest();
}
double adapter_class_1::average(){
    return adaptee::average();
}

int adapter_object_2::add(book a){
    int ret;
    ad.add(a, ret);
    return ret;
}
int adapter_object_2::remove(book a){
    int ret;
    ad.remove(a, ret);
    return ret;
}
book *adapter_object_2::find(string BN){
    book *p;
    ad.find(BN, p);
    return p;
}
void adapter_object_2::clean(){
    ad.clean();
}
book adapter_object_2::mostExpensive(){
    return ad.mostExpensive();
}
book adapter_object_2::cheapest(){
    return ad.cheapest();
}
double adapter_object_2::average(){
    return ad.average();
}

int adapter_class_2::add(book a){
    int ret = 0;
    adaptee::add(a, ret);
    return ret;
}
int adapter_class_2::remove(book a){
    int ret = 0;
    adaptee::remove(a, ret);
    return ret;
}
book *adapter_class_2::find(string BN){
    book *p;
    adaptee::find(BN, p);
    return p;
}
void adapter_class_2::clean(){
    adaptee::clean();
}
book adapter_class_2::mostExpensive(){
    return adaptee::mostExpensive();
}
book adapter_class_2::cheapest(){
    return adaptee::cheapest();
}
double adapter_class_2::average(){
    return adaptee::average();
}

int adapter_object_3::add(book a){
    int ret;
    ad.add(a, ret);
    return ret;
}
int adapter_object_3::remove(book a){
    int ret;
    ad.remove(a, ret);
    return ret;
}
book *adapter_object_3::find(string BN){
    book *p;
    ad.find(BN, p);
    return p;
}
void adapter_object_3::clean(){
    ad.clean();
}
book adapter_object_3::mostExpensive(){
    return ad.mostExpensive();
}
book adapter_object_3::cheapest(){
    return ad.cheapest();
}
double adapter_object_3::average(){
    return ad.average();
}

int adapter_class_3::add(book a){
    int ret = 0;
    adaptee::add(a, ret);
    return ret;
}
int adapter_class_3::remove(book a){
    int ret = 0;
    adaptee::remove(a, ret);
    return ret;
}
book *adapter_class_3::find(string BN){
    book *p;
    adaptee::find(BN, p);
    return p;
}
void adapter_class_3::clean(){
    adaptee::clean();
}
book adapter_class_3::mostExpensive(){
    return adaptee::mostExpensive();
}
book adapter_class_3::cheapest(){
    return adaptee::cheapest();
}
double adapter_class_3::average(){
    return adaptee::average();
}

void test(Lookuptable *ptr){
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
    val.assign("動畫圖解資料庫系統理論-使用Access 2010實作(第二版)", "李春雄", 600);
    cout << ptr->add(val) << endl; //回傳成功(1)

    book tmp = ptr->mostExpensive();
    cout << "最貴的書: " << tmp << endl;
    // 最貴的書: "資料庫系統理論－使用SQL Server 2008" "李春雄" 650
    tmp = ptr->cheapest();
    cout << "最便宜的書: " << tmp << endl;
    // 最便宜的書: "資料庫系統－MTA認證影音教學" "李春雄" 336
    cout << "平均書價格: " << ptr->average() << endl;
    // 平均書價格: ...

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
    val.assign("動畫圖解資料庫系統理論-使用Access 2010實作(第二版)", "李春雄", 600);
    cout << ptr->add(val) << endl; //失敗回傳0

    tmp = ptr->mostExpensive();
    cout << "最貴的書: " << tmp << endl;
    tmp = ptr->cheapest();
    cout << "最便宜的書: " << tmp << endl;
    cout << "平均書價格: " << ptr->average() << endl;

    cout << "Test remove" << endl;
    val.assign("精通光學辨識技術:應用ABBYY FineReader 11 OCR", "黃敦義", 371);
    if (ptr->remove(val))
        cout << "成功 " << val << endl;
    // 成功 "精通光學辨識技術：應用ABBYY FineReader 11 OCR" "黃敦義" 371
    else
        cout << "失敗" << endl; // 失敗
    val.assign("電腦網路概論(第二版)", "陳雲龍", 420);
    if (ptr->remove(val))
        cout << "成功 " << val << endl;
    // 成功 "電腦網路概論(第二版)" "陳雲龍" 420
    else
        cout << "失敗" << endl; // 失敗
    val.assign("動畫圖解資料庫系統理論-使用Access 2010實作(第二版)", "李春雄", 600);
    if (ptr->remove(val))
        cout << "成功 " << val << endl;
    // 成功 ""動畫圖解資料庫系統理論－使用Access 2010實作(第二版)" "李春雄" 600
    else
        cout << "失敗" << endl; // 失敗
    val.assign("動畫圖解資料庫系統理論-使用Access 2010實作(第二版)", "李春雄", 600);
    if (ptr->remove(val))
        cout << "成功 " << val << endl;
    // 成功 ""動畫圖解資料庫系統理論－使用Access 2010實作(第二版)" "李春雄" 600
    else
        cout << "失敗" << endl; // 失敗
    //*
    string BN;
    cout << "Test find" << endl;
    BN = "精通光學辨識技術:應用ABBYY FineReader 11 OCR";
    if (vptr = ptr->find(BN))
        cout << "成功 " << *vptr << endl; // 成功
    else
        cout << "失敗" << endl; // 失敗
    BN = "電腦網路概論(第二版)";
    if (vptr = ptr->find(BN))
        cout << "成功 " << *vptr << endl; // 成功
    else
        cout << "失敗" << endl; // 失敗
    BN = "動畫圖解資料庫系統理論-使用Access 2010實作(第二版)";
    if (vptr = ptr->find(BN))
        cout << "成功 " << *vptr << endl; // 成功
    else
        cout << "失敗" << endl; // 失敗
//*
    tmp = ptr->mostExpensive();
    cout << "最貴的書: " << tmp << endl;
    tmp = ptr->cheapest();
    cout << "最便宜的書: " << tmp << endl;
    cout << "平均書價格 : " << ptr->average() << endl;
//*/

    cout << "Test clean" << endl;
    ptr->clean();
    val.assign("資料庫系統-MTA認證影音教學", "李春雄", 336);
    if (ptr->remove(val))
        cout << "成功 " << val << endl;
    // 成功 ""動畫圖解資料庫系統理論－使用Access 2010實作(第二版)" "李春雄" 600
    else
        cout << "失敗" << endl; // 失敗
    BN = "精通光學辨識技術:應用ABBYY FineReader 11 OCR";
    if(vptr = ptr->find(BN))
		cout << "成功 "<< *vptr << endl;  	   	// 成功  
    else
	    cout << "失敗" << endl;  	   		// 失敗
    BN = "精通光學辨識技術:應用ABBYY FineReader 11 OCR";
    if(vptr = ptr->find(BN))
	    cout << "成功 "<< *vptr << endl;  	   	// 成功  
    else
		cout << "失敗" << endl;  	   		// 失敗

/////////////////////////////////////////////////////////////////////
// 壓力測試
/////////////////////////////////////////////////////////////////////
//*
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
        ptr->find(str2);		
	}
    
    cout << "Test remove" << endl;
	for(i=0; i<1000; i++){
        itoa(i, buffer, 10);
        str2 = str1 + buffer;
        val = book(str2, str2, rand());
        ptr->remove(val);
 	}//*/
}
void init(){
    cheap.price = 1000000000;
    Expensive.price = 0;
    total = sum = 0;
}

int main(){
    //*
    Lookuptable *ptr;
// Adaptee 1
    cout << "test adapter_class_1" << endl;
    init();
    ptr = new adapter_class_1;
    test(ptr);
    delete ptr;

    cout << "test adapter_object_1" << endl;
    init();
    ptr = new adapter_object_1;
    test(ptr);
    delete ptr;
//*
// Adaptee 2
    cout << "test adapter_class_2" << endl;
    init();
    ptr = new adapter_class_2;
    test(ptr);
    delete ptr;

    cout << "test adapter_object_2" << endl;
    init();
    ptr = new adapter_object_2;
    test(ptr);
    delete ptr;

// Adaptee 3
    cout << "test adapter_class_3" << endl;
    init();
    ptr = new adapter_class_3;
    test(ptr);
    delete ptr;

    cout << "test adapter_object_3" << endl;
    init();
    ptr = new adapter_object_3;
    test(ptr);
    delete ptr;
    //*/
}