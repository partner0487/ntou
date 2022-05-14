/*
Author: Xiaoyo
num: 01057020
time: 2022 / 05 / 14
//*/
#include "iostream"
#include "time.h"
#include "string.h"
using namespace std;

struct book{
    const char *bookName, *authors;
    int price;
};

template<class type>
struct node{
    node<type> *l,  *r;
    type d;
};

void printFun(book x){
    cout << x.bookName << " " << x.authors << " " << x.price << endl;
}
int cmp(book a, book b){
    int res = strcmp(a.bookName, b.bookName);
    return res;
}

template<class type>
void insert(node<type> *&now, type v){
    if(now == NULL){
        now = new node<type>();
        now->d = v;
        return;
    }
    if(cmp(v, now->d) > 0) insert(now->r, v);
    else                   insert(now->l, v);
}
template<class type>
void inorder(node<type> *now){
    if(now != NULL){
        inorder(now->l);
        printFun(now->d);
        inorder(now->r);
    }
}
template<class type>
void preorder(node<type> *now){
    if(now != NULL){
        printFun(now->d);
        preorder(now->l);
        preorder(now->r);
    }
}
template<class type>
void postorder(node<type> *now){
    if(now != NULL){
        postorder(now->l);
        postorder(now->r);
        printFun(now->d);
    }
}

void setBook(book &it, const char* bookName, const char *authors, int price){
    it.bookName = bookName;
    it.authors = authors;
    it.price = price;
}

void testBook(){
    node<book> *root = NULL;
	book item;
	
    cout << "The books begin placed in the tree are: " << endl;

	setBook(item, "精通光學辨識技術:應用ABBYY FineReader 11 OCR", "黃敦義",  371);
	printFun(item);
	insert(root, item);

	setBook(item, "VISUAL FORTRAN程式設計與開發", "張嘉強、陳鴻智", 400);
	printFun(item);
	insert(root, item);

	setBook(item, "程式設計-使用C++", "黃建庭", 420);
	printFun(item);
	insert(root, item);

	setBook(item, "資料庫系統:MTA認證影音教學", "李春雄", 336);
	printFun(item);
	insert(root, item);

	setBook(item, "輕鬆搞定Google雲端技術:Maps.Android.App Engine.Cloud SQL與電子商務API實例解析", "陳世興", 560);
	printFun(item);
	insert(root, item);

	setBook(item, "人工智慧：智慧型系統導論(第三版) ", "李聯旺 廖珗洲 謝政勳", 590);
	printFun(item);
	insert(root, item);

	setBook(item, "電腦網路概論(第二版)", "陳雲龍", 420);
	printFun(item);
	insert(root, item);

	setBook(item, "網際網路與電子商務(第三版)", "朱正忠", 450);
	printFun(item);
	insert(root, item);

	setBook(item, "資料庫系統理論-使用SQL Server 2008", "李春雄", 650);
	printFun(item);
	insert(root, item);

	setBook(item, "動畫圖解資料庫系統理論-使用Access 2010實作(第二版)", "李春雄", 600);
	printFun(item);
	insert(root, item);

	setBook(item, "精通光學辨識技術:應用ABBYY FineReader 11 OCR", "黃敦義", 371);
	printFun(item);
	insert(root, item);

	setBook(item, "VISUAL FORTRAN程式設計與開發", "張嘉強、陳鴻智", 400);
	printFun(item);
	insert(root, item);

	setBook(item, "程式設計-使用C++", "黃建庭", 420);
	printFun(item);
	insert(root, item);

	setBook(item, "資料庫系統-MTA認證影音教學", "李春雄", 336);
	printFun(item);
	insert(root, item);

	setBook(item, "輕鬆搞定Google雲端技術:Maps.Android.App Engine.Cloud SQL與電子商務API實例解析", "陳世興", 560);
	printFun(item);
	insert(root, item);

    cout << endl;
    cout << "Preorder: " << endl;
    preorder(root);
    cout << endl;
    cout << "Inorder: " << endl;
    inorder(root);
    cout << endl;
    cout << "Postorder: " << endl;
    postorder(root);
}

int main(){
    testBook();
}