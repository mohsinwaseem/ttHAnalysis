#ifndef Table_cxx
#define Table_cxx

//#define DEBUG
#include "Table.h"
#include <iomanip>  // std::setprecision

//****************************************************************************
Table::Table(string titleRow, 
	     string format,
	     string tableSpecs)
//****************************************************************************
{
  
  // Save settings to internal variables
  format_     = format;
  titleRow_   = titleRow + rowEnd_;
  tableWidth_ = 0; 
  tableSpecs_ = tableSpecs;

  // Check that there are at least 2 columns
  FindStringInString("|", titleRow_);

  // Check that table format is ok. Inform user of delimiter assumption
  if (format_.compare("LaTeX") == 0){
    ConvertTitleRowToLatex(titleRow_);
    FindStringInString("&", titleRow_);
    SetupLatex();
  }
  else if (format_.compare("Text") == 0) SetupText();
  else
    {
      cout << "E R R O R ! Table::Table(...) - Unknown table format \"" << format_ << "\""
	   << "\nPlease select \"LaTeX\" or \"Plain\".\n EXIT" << endl;
      exit(1);
    }
  
  // Get number of columns and Reserve columns vector size
  GetNumberOfColumns_(titleRow_);
  vector< int> empty;
  for(int i = 0; i <= nColumns_; i++) columnMaxWidths_.push_back(empty);

}


//****************************************************************************
void Table::FindStringInString(string stringToFind, 
			       string stringToSearch)
//****************************************************************************
{

  size_t found = stringToSearch.find(stringToFind);
  if (found == std::string::npos)
    {
      cout << "E R R O R ! Table::FindStringInString_(...) Could not find string \"" << stringToFind << "\" inside string \"" << stringToSearch << "\". "
	   << "EXIT" << endl;
      exit(1);
    }
  return;
}

  
//****************************************************************************
void Table::AppendRowEndToEachRow_(void)
//****************************************************************************
  {
    titleRow_.append( rowEnd_ ); 
    for (size_t i = 0; i < rows_.size(); i ++) rows_.at(i).append( rowEnd_ ); 
  }


//****************************************************************************
void Table::GetNumberOfColumns_(string text)
//****************************************************************************
{
  
  int counter = 0;
  for (size_t i = 0; i < text.size(); i++)
    {       
      if (text[i] == delimiter_ ) counter++;
    }

  nColumns_ = counter+1;

}


//****************************************************************************
int Table::GetNumberOfCharacters_(string text)
//****************************************************************************
{
  
  int counter = 0;
  for (size_t i = 0; i < text.size(); i++) counter++;

  return counter;
}


//****************************************************************************
void Table::SetupLatex(void)
//****************************************************************************
{

  delimiter_   = "&";
  rowEnd_      = " \\\\";
  hLine_       = "\\hline";
  commentLine_ = string(20, '%');  

  return;
}


//****************************************************************************
void Table::SetupText(void)
//****************************************************************************
{

  delimiter_   = "|";
  rowEnd_      = ""; 
  hLine_       = string(20, '=');
  commentLine_ = string(20, '%');
  
  return;
}


//****************************************************************************
void Table::AddRowColumn(size_t iRow, 
			 string text)
//****************************************************************************
{

  if (iRow < rows_.size() ) rows_.at(iRow).append( " " + delimiter_  + " " + text);
  else if (iRow == rows_.size() ) rows_.push_back(text);
  else
    {
      cout << "E R R O R ! Table::AddRowColumn(...) - Cannot add columns number \"" << iRow
	   << " as there are only \"" << rows_.size() << "\" at the moment in the table." << endl;
      exit(1);
    }
  
  return;
}


//****************************************************************************
void Table::BeginTabular_(void)
//****************************************************************************
{
  
  if (tableSpecs_.compare("") == 0) for (int i = 0; i <= nColumns_; i ++) tableSpecs_.append(" c ");

  if (format_.compare("Text") == 0)  return;
  
  AddTopRow( commentLine_ );
  AddTopRow("\\begin{table}");
  AddTopRow("\\begin{center}");
  AddTopRow("\\begin{tabular}{" + tableSpecs_ + "}");
    
  return;
}


//****************************************************************************
void Table::PrintTitleRow(void)
//****************************************************************************
{
  
 PrintHorizontalLine();
  
  // Get the text for the title row
  std::string rowText = titleRow_;
  size_t pos          = 0;
  int columnNumber    = 0;
  int textWidth       = 0;
  std::string columnText;
  vector<int> cWidths;
      
  // Loop over row text breaking string into delimiter tokens (columns)
  while ( (pos = rowText.find( delimiter_) ) != string::npos){
    
    // Get max text-width for given column for each row
    cWidths = columnMaxWidths_.at(columnNumber);
    textWidth = *max_element(cWidths.begin(), cWidths.end());
    
    // Get column text entry
    columnText = rowText.substr(0, pos);
    
    // Print formatted row with all columns
    cout << left << setw( textWidth ) << columnText << delimiter_;
    
    // Delete printed column to move on to the next (erase row text from 0 character to token + delimiter_ character)
    rowText.erase(0, columnText.length() + delimiter_.length() );
    columnNumber++;
  }
  
  // Print the last column outside the while-loop
  cout << setw( textWidth ) << rowText << endl; 
  
  PrintHorizontalLine();
  
  return;
}


//****************************************************************************
void Table::EndTabular_(void)
//****************************************************************************
{

  if (format_.compare("LaTeX") == 0) 
    {
      AddBottomRow(hLine_);
      AddBottomRow("\\end{tabular}");
      AddBottomRow("\\end{center}");
      AddBottomRow("\\end{table}");
      AddBottomRow( commentLine_ );
    }
  else if (format_.compare("Text") == 0) 
    {
      // AddBottomRow( hLine_ );
    }
  AddBottomRow("");
  
  return;
}


//****************************************************************************
void Table::PrintTableRows(void)
//****************************************************************************
{
  
  // Loop over rows of text
  for (size_t j = 0; j < rows_.size(); j ++) {

    // Get the text for the entire row
    std::string rowText = rows_.at(j);
    size_t pos          = 0;
    int columnNumber    = 0;
    int textWidth       = 0;
    std::string columnText;
    vector<int> cWidths;
      
    // Convert each column to LaTeX format if required 
    ConvertStringToLatex(rowText);

    // Loop over row text breaking string into delimiter tokens (columns)
    while ( (pos = rowText.find( delimiter_) ) != string::npos){      

      // Get max text-width for given column for each row
      cWidths = columnMaxWidths_.at(columnNumber);
      textWidth = *max_element(cWidths.begin(), cWidths.end());

      // Get column text entry
      columnText = rowText.substr(0, pos);
      
      // Print formatted row with all columns
      cout << left << setw( textWidth ) << columnText << delimiter_;
      

      // Delete printed column to move on to the next (erase row text from 0 character to token + delimiter_ character)
      rowText.erase(0, columnText.length() + delimiter_.length() );
      columnNumber++;
    }

    // Print the last column outside the while-loop
    cout << setw( textWidth ) << rowText << endl; 

  }

  return;
}


//****************************************************************************
void Table::ConvertStringToLatex(string &text)
//****************************************************************************
{

  // Ensure that LaTeX mode is enabled
  if (format_.compare("LaTeX") != 0) return;

  // Replace "~" with "*"
  // replace( text.begin(), text.end(), '~', '*'); 

  // Replace "_" with "\_"
  int nChars =  text.length();
  vector<int> v_pos;
  for (int i = 1; i < nChars; i++)
    {
      if (text.at(i) !=  '_') continue;
      v_pos.push_back(i);
    } 
  for (int j=(int) v_pos.size()-1; j>= 0; j--) text.insert( v_pos.at(j), "\\");

  return;
}


//****************************************************************************
void Table::ConvertTitleRowToLatex(string &titleRow)
//****************************************************************************
{

  replace( titleRow.begin(), titleRow.end(), '|', '&'); 
  
  return;
}


//****************************************************************************
void Table::GetColumnWidths_(void)
//****************************************************************************
{

  // Include the titleRow in the determination of maximum column width (delete this row before exiting the function)
  rows_.push_back(titleRow_);
  
  // Loop over rows of text
  for (size_t j = 0; j < rows_.size(); j ++) {
    
    // Get the text for the entire row
    std::string rowText = rows_.at(j);
    size_t pos = 0;
    std::string columnText;

    int columnNumber = 0;
    // Loop over row text breaking string into delimiter tokens (columns)
    while ( (pos = rowText.find( delimiter_) ) != string::npos){
      
      // Get column text entry
      columnText = rowText.substr(0, pos);
      
      // Get column width
      int cWidth = columnText.length();

      // Save the column width for this row & column
      columnMaxWidths_.at(columnNumber).push_back( cWidth );
      
      // Delete printed column to move on to the next (erase row text from 0 character to token + delimiter_ character)
      rowText.erase(0, columnText.length() + delimiter_.length() );

      // Increment counter
      columnNumber++;
    }

  }
  
  // Now determine the total table width
  for( size_t i = 0; i < columnMaxWidths_.size(); i++)
    {   
      if (columnMaxWidths_.at(i).size() == 0) continue;
      tableWidth_  += *max_element( columnMaxWidths_.at(i).begin(), columnMaxWidths_.at(i).end() );
    }

  // Delete titleRow which was added temporarily
  rows_.pop_back();

  return;
}


//****************************************************************************
void Table::EnsureRowsHaveCorrectColumns_(void)
//****************************************************************************
{

  // For-loop: Rows
  for (size_t j = 0; j < rows_.size(); j ++) {
    
    int nColumns = 1;
    size_t pos   = 0;
    std::string rowText = rows_.at(j);
    std::string columnText;

    // For-loop: Columns
    while ( (pos = rowText.find( delimiter_) ) != string::npos){
      
      // Get column text entry, delete and increment
      columnText = rowText.substr(0, pos);
      rowText.erase(0, columnText.length() + delimiter_.length() );
      nColumns++;
    }
    
    // If columns missing fill with pre-defined text
    int diff = abs(nColumns - nColumns_);
    if (diff != 0){ for (int i = 0; i < diff; i++) AddRowColumn(j,  ""); }
    // if (diff != 0){ for (int i = 0; i < diff; i++) AddRowColumn(j,  " - "); }
    // if (diff != 0){ for (int i = 0; i < diff; i++) AddRowColumn(j,  "N/A"); }
    
  }
  return;

}


//****************************************************************************
void Table::Print(void)
//****************************************************************************
{

  // Sanity check (all columns are filled). If not fill them
  EnsureRowsHaveCorrectColumns_();

  // Append end-of-row characters (rowEnd_)
  AppendRowEndToEachRow_();

  // Re-adjust the width of the horizontal lines to the total table width
  GetColumnWidths_();

  if (format_.compare("Text") == 0) SetHorizontalLine( string(tableWidth_ + rowEnd_.length() + nColumns_*2, '=') );
  SetCommentLine(string(tableWidth_ + rowEnd_.length() + nColumns_*3, '%') );

  // Make table
  BeginTabular_();
  EndTabular_();

  // Print table
  PrintRow(rowsTop_);
  PrintTitleRow();
  PrintTableRows();
  PrintRow(rowsBottom_);

  return;

}

#endif
