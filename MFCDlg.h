
// MFCDlg.h: 头文件
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
#pragma once


// CMFCDlg 对话框
class CMFCDlg : public CDialogEx
{
// 构造
public:
	CMFCDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton B1_NAME;
	afx_msg void OnBnClickedButton5();
	CButton B2_NAME;
	CButton B3_NAME;
	CButton B4_NAME;
	CString KEY;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CString IMG_PATH;
	afx_msg void OnStnClickedStatic1();
	CStatic past_public;
};
