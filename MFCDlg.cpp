
// MFCDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFC.h"
#include "MFCDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include<algorithm>
#include <gdiplus.h>
#pragma comment(lib,"gdiplus.lib")
using namespace Gdiplus;
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCDlg 对话框



CMFCDlg::CMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, B1_NAME);
	DDX_Control(pDX, IDC_BUTTON2, B2_NAME);
	DDX_Control(pDX, IDC_BUTTON3, B3_NAME);
	DDX_Control(pDX, IDC_BUTTON4, B4_NAME);

	DDX_Control(pDX, IDC_STATIC1, past_public);
}

BEGIN_MESSAGE_MAP(CMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCDlg::OnBnClickedButton4)

	ON_STN_CLICKED(IDC_STATIC1, &CMFCDlg::OnStnClickedStatic1)
END_MESSAGE_MAP()


// CMFCDlg 消息处理程序

BOOL CMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。



	B1_NAME.SetWindowTextW(L"点击下一题");
	B2_NAME.SetWindowTextW(L"点击下一题");
	B3_NAME.SetWindowTextW(L"点击下一题");
	B4_NAME.SetWindowTextW(L"点击下一题");
	int key;



	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//人数统计
int FindUaername() {
	ifstream outFile("Data.csv", ios::in);
	if (!outFile)
	{
		cout << "打开文件失败！" << endl;
		exit(1);
	}
	int i = 0;
	string line;
	string field;
	while (getline(outFile, line))//getline(inFile, line)表示按行读取CSV文件中的数据
	{
		string field;
		istringstream sin(line); //将整行字符串line读入到字符串流sin中
		getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
		getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
		getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
		i++;
	}
	outFile.close();
	return i;

}








//随机列表生成（长度4升序）
vector<int> Rnums() {
	srand((unsigned)time(0)); // 产生随机种子
	vector<int> res;
	for (int i = 0; i < 4; ++i) {
		int r = rand() % FindUaername();
		vector<int>::iterator it = find(res.begin(), res.end(), r);
		if (it != res.end())
			--i;
		else
			res.push_back(r);
	}

	sort(res.begin(), res.end());
	return res;
}


//题目答案生成
vector<string> Rtitle(vector<int> Rnums) {
	int key;//答案
	srand((int)time(0));  //产生随机种子
	key = rand() % 4;
	vector<string> tit;
	ifstream outFile("Data.csv", ios::in);
	if (!outFile)
	{
		cout << "打开文件失败！" << endl;
		exit(1);
	}
	int k = 0;
	int n = 0;
	cout << "选项：" << endl;
	string line;
	string img_path;
	string name;
	while (getline(outFile, line))//getline(inFile, line)表示按行读取CSV文件中的数据
	{
		if (k == Rnums[n]) {
			string field;
			istringstream sin(line); //将整行字符串line读入到字符串流sin中
			getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
			cout << n + 1 << "号" << field.c_str() << endl;
			tit.push_back(field.c_str());
			if (n == key) {
				name = field.c_str();

			}
			getline(sin, field, ',');
			getline(sin, field); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
			if (n == key) {
				img_path = field.c_str();

			}
			++n;
			if (n == 4) {
				break;
			}
		}
		k++;
	}
	cout << "图片路径" << img_path << endl;

	int ans;
	cout << "请输入图片中的人（选项前的序号）：";
	cin >> ans;
	if (ans == key + 1) {
		cout << "正确" << endl;
	}
	else {
		cout << "回答错误" << endl;
		cout << "正确答案：" << name << endl;


	}
	cout << "-------------------------" << endl;
	outFile.close();

	string res;
	stringstream ss;
	ss << key;
	ss >> res;
	tit.push_back(res);
	return tit;
}





void CMFCDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码

	CString str;
	vector<string> obj = Rtitle(Rnums());
	str = obj[4].c_str();
	KEY = str;
	
	str = obj[0].c_str();
	B1_NAME.SetWindowTextW(str);
	str = obj[1].c_str();
	B2_NAME.SetWindowTextW(str);
	str = obj[2].c_str();
	B3_NAME.SetWindowTextW(str);
	str = obj[3].c_str();
	B4_NAME.SetWindowTextW(str);




	//GetDlgItemText(IDC_BUTTON1, i); //取按钮标题
	//GetDlgItem(IDC_BUTTON1)->SetWindowText(_T(obj[0]));
	//if (i == _T("开始"))
	//	GetDlgItem(IDC_BUTTON1)->SetWindowText(_T("停止"));
	//else
	//	GetDlgItem(IDC_BUTTON1)->SetWindowText(_T("开始"));
	
	CStatic* pWnd = (CStatic*)GetDlgItem(IDC_STATIC1); // 得到 Picture Control 句柄
	pWnd->ModifyStyle(0, SS_BITMAP); // 修改它的属性为位图
	pWnd->SetBitmap((HBITMAP)::LoadImage(NULL, _T("test.bmp"),
		IMAGE_BITMAP,
		0,
		0,
		LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE));


}






void CMFCDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	
	if (KEY == "0") {
		CString str = _T("正确");
		MessageBox(str, _T("提示！"));
	}
	else {
		CString str = _T("错误");
		MessageBox(str, _T("提示！"));
	}
}



void CMFCDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (KEY == "1") {
		CString str = _T("正确");
		MessageBox(str, _T("提示！"));
	}
	else {
		CString str = _T("错误");
		MessageBox(str, _T("提示！"));
	}


}


void CMFCDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (KEY == "2") {
		CString str = _T("正确");
		MessageBox(str, _T("提示！"));
	}
	else {
		CString str = _T("错误");
		MessageBox(str, _T("提示！"));
	}
}


void CMFCDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (KEY == "3") {
		CString str = _T("正确");
		MessageBox(str, _T("提示！"));
	}
	else {
		CString str = _T("错误");
		MessageBox(str, _T("提示！"));
	}
}







void CMFCDlg::OnStnClickedStatic1()
{
	// TODO: 在此添加控件通知处理程序代码
}
