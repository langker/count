// countDlg.cpp : implementation file
//

#include "stdafx.h"
#include "count.h"
#include "countDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCountDlg dialog

CCountDlg::CCountDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCountDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCountDlg)
	m_name = _T("");
	m_code = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCountDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCountDlg)
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_code);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCountDlg, CDialog)
	//{{AFX_MSG_MAP(CCountDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCountDlg message handlers

BOOL CCountDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCountDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCountDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCountDlg::OnButton1() 
{
	UpdateData(1);
	char h[100]={0};
	int g=0;
    char mishi[]={"youarefailed!!"};
    CString m_Sname1,m_Sname2,m_Scode1,m_Scode2;
	for(int a=1;a<m_name.GetLength();a=a+2)     //同上，只不过把计算方式改成了加法，
	{                                           //算得m_Sname2
		g=mishi[a]+m_name[a];
        itoa(g,h,16);
		m_Sname2=m_Sname2+h;
	}
	for(int i=0;i<m_name.GetLength();i=i+2)       //对用户名的奇数位与密匙的奇数位一次进行
	{                                             // 异或比较，转为16进制后累加为m_Sname1
		g=mishi[i]^m_name[i];                     
        itoa(g,h,16);                             
		m_Sname1=m_Sname1+h;                      
	}
    m_Sname2=m_Sname2+m_Sname1;
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_Sname2);
}
