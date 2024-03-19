/*MIT License

Copyright (c) 2022 Shahryar Ahmad 

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/
#ifndef PARSER_H_
#define PARSER_H_
#include "token.h"
#include "ast.h"
#include "programinfo.h"
#include "lexer.h"
#include <algorithm>
#include <queue>


int len(std::string s);
std::string substr(int x,int y,const std::string& s);
std::vector<std::string> split(std::string s,const std::string& x);
std::string lstrip(std::string s);
std::string replace(std::string x,std::string y,std::string s);//Replaces only once

Node* NewNode(NodeType type,string val="");
void stripNewlines(vector<Token>& tokens);
int matchRPRight(int k,const vector<Token>& tokens);
int findBeginList(int k,const vector<Token>& tokens);
int findLCBRight(int k,const vector<Token>& tokens);
int findToken(Token t,int start,const vector<Token>& tokens);
int matchRP(int k,const vector<Token> tokens);
int findEndList(int k,const vector<Token>& tokens);
int findRCB(int k,const vector<Token>& tokens);
void deleteAST(Node* ast);
void CopyAst(Node*& dest,Node* src);

// Function to print AST in tablular form
void printAST(Node* n,int spaces = 0);
int findTokenConsecutive(Token t,int start,const vector<Token>& tokens);


class Parser
{
private:
  vector<Token> known_constants;
  vector<string> prefixes = {""};//for namespaces 
  std::unordered_map<string,vector<string>>* refGraph;
  string currSym;
  vector<string>* files;
  vector<string>* sources;
  string filename;
  size_t line_num = 1;
  int* num_of_constants;
  std::string aux;
  bool foundYield = false;
  //Context
  bool infunc;
  bool inclass;
  bool inloop;
  bool inif;
  bool inelif;
  bool inelse;
  bool intry;
  bool incatch;
  //in class method = inclass && infunc
  inline bool atGlobalLevel()
  {
    return (!infunc && !inclass && !inloop
     && !inif && !inelif && !inelse && !intry && !incatch);
  }
  inline bool isValidCtxForFunc()
  {
        return (!infunc  && !inloop
     && !inif && !inelif && !inelse && !intry && !incatch);
  }
public:
  void init(string fname,ProgramInfo& p);
  void parseError(string type,string msg);
  bool addSymRef(string name);
  Node* parseExpr(const vector<Token>& tokens);
  Node* parseStmt(vector<Token> tokens);
  Node* parse(const vector<Token>& tokens);
};
#endif
