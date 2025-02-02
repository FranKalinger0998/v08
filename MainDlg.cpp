#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, lista);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::AddButton)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::DeleteButton)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	lista.InsertColumn(0, "Title", LVCFMT_LEFT, 100, 20);
	lista.InsertColumn(1, "Year", LVCFMT_CENTER, 100, 20);
	lista.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(0);

	return TRUE;
}

void MainDlg::AddButton()
{

	CString movieName;
	CString movieYear;
	GetDlgItemText(IDC_EDIT1, movieName);
	GetDlgItemText(IDC_EDIT2, movieYear);
	int inputIndex = lista.GetItemCount();

	if (movieName == "" || movieYear == "")
		return;

	lista.InsertItem(inputIndex, movieName);
	lista.SetItemText(inputIndex, 1, movieYear);
	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
	GetDlgItem(IDC_BUTTON2)->EnableWindow(true);

}


void MainDlg::DeleteButton()
{	
	int x = lista.GetNextItem(-1, LVNI_SELECTED);
	if (x == -1) return;
	lista.DeleteItem(x);
	if (lista.GetItemCount() == 0)
		GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
}
