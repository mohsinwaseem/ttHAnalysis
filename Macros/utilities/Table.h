#ifndef Table_h
#define Table_h

#include <algorithm>
using namespace std;

class Table{
 public:
  // Default and overloaded constructors & destructors
  Table() {}; 
  Table(string titleRow, string format, string tableSpecs="");
  ~Table() {};

  // Member Functions
  void Print(void);
  void SetupText(void);
  void SetupLatex(void);
  void AddNewRowColumn(string text){   rows_.push_back(text); }
  void AddRowColumn(size_t iRow, string text);
  void AddTopRow(string text){ rowsTop_.push_back(text); }
  void AddBottomRow(string text){ rowsBottom_.push_back(text); }
  void PrintRow(vector<string> row){ for (size_t i = 0; i < row.size(); i++){ cout << row.at(i) << endl;} }
  void PrintHorizontalLine(void){ cout << hLine_ << endl; } 
  void PrintTitleRow(void);
  void PrintTableRows(void);
  void SetTableSpecs(string text){ tableSpecs_ = text; }
  void SetDelimiter(string text){ delimiter_ = text; }
  void SetNumberOfColumns(int number){ nColumns_ = number; }
  void SetTableWidth(int width){ tableWidth_ = width; }
  void SetRowEnd(string text){ rowEnd_ = text; }
  void SetHorizontalLine(string text){ hLine_ = text; }
  void SetCommentLine(string text){ commentLine_ = text; }
  void ConvertStringToLatex(string &text);
  void ConvertTitleRowToLatex(string &titleRow);
  void FindStringInString(string stringToFind, 
			  string stringToSearch);
  // Variables


  private:
  // Member Functions
  void GetNumberOfColumns_(string text);
  int GetNumberOfCharacters_(string text);
  void GetColumnWidths_(void);
  void BeginTabular_(void);
  void EndTabular_(void);
  void EnsureRowsHaveCorrectColumns_();
  void AppendRowEndToEachRow_(void);

  // Variables
  int nColumns_;
  int tableWidth_;
  string titleRow_;  
  string format_;
  string tableSpecs_;
  string delimiter_;
  string rowEnd_;
  string hLine_;
  string commentLine_;
  vector<string> rows_;
  vector<string> rowsTop_;
  vector<string> rowsBottom_;
  vector< vector<int> > columnMaxWidths_;

};

#endif
