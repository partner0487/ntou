/*
Author: Xiaoyo
num: 01057020
time: 2022 / 05 / 14
//*/
#include "iostream"
#include "string.h"
using namespace std;

struct book{
    const char *bookName, *authors;
    int price;
};
struct node{
    node *l, *r;
    book content;
};

void printFun(book a){
    cout << a.bookName << " " << a.authors << " " << a.price << endl;
}

void insert(node *&now, book it){
    if(now == NULL){
        now = new node();
        now->content = it;
        return;
    }
    int res = strcmp(it.bookName, now->content.bookName);
    if(res > 0) insert(now->r, it);
    else        insert(now->l, it);
}

void preorder(node *now){
    if(now != NULL){
        printFun(now->content);
        preorder(now->l);
        preorder(now->r);
    }
}
void inorder(node *now){
    if(now != NULL){
        inorder(now->l);
        printFun(now->content);
        inorder(now->r);
    }
}
void postorder(node *now){
    if(now != NULL){
        postorder(now->l);
        postorder(now->r);
        printFun(now->content);
    }
}

void setBook(book &it, const char* bookName, const char *authors, int price){
    it.bookName = bookName;
    it.authors = authors;
    it.price = price;
}

void traversal(node *now){
    cout << "Preorder: " << endl;
    preorder(now);
    cout << endl;
    cout << "Inorder: " << endl;
    inorder(now);
    cout << endl;
    cout << "postorder: " << endl;
    postorder(now);
}

void testBook(){
    node *root = NULL;
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
    traversal(root);
}

int main(){
    testBook();
}