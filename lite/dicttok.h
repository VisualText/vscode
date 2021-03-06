
/*******************************************************************************
Copyright (c) 2011-12 by Text Analysis International, Inc.
All rights reserved.
********************************************************************************
*
* NAME:	DICTTOK.H
* FILE:	lite\tok.h
* CR:		07/29/11 AM.
* SUBJ:	Class for tokenization.
* NOTE:	
*
*******************************************************************************/

#ifndef DICTTOK_H_
#define DICTTOK_H_

#include "pn.h"
//#include "tree.h"
#include "lite/algo.h"
#include "htab.h"

/********************************************
* CLASS:	DICTTOK
* CR:		10/09/98 AM.
* SUBJ:	Tokenization class.
* NOTE:	Tokenization converts a buffer into a parse tree.
*			Since using Parse instance, should get rid of most of what's
*			here!
********************************************/

class DICTTok : public Algo
{
public:
	DICTTok();					// Constructor.
	//DICTTok(Parse *);			// Constructor that performs the tokenization!
	DICTTok(const DICTTok &orig);	// Copy constructor.   // 12/03/98 AM.

	bool getBad();					// 01/15/99 AM.
	void setBad(bool);			// 01/15/99 AM.
	bool getZapwhite();        // 08/16/11 AM.
	void setZapwhite(bool);    // 08/16/11 AM.

	//Parse *getParse();
	//void   setParse(Parse *);

	virtual Algo &dup();					// 12/03/98 AM.
	virtual void setup(_TCHAR *s_data);					// 12/04/98 AM.
	bool Execute(Parse *, Seqn *);	// Perform the tokenization.
	bool Tokenize(Parse *);	// Perform the tokenization.
	void DICTTok::FirstToken(Tree<Pn> *tree, Htab *htab, /*DU*/ _TCHAR* *buf,
										long &start, Node<Pn>* &last,
										long &line	// Line number.		// 05/17/01 AM.
										);

	inline bool DICTTok::NextToken(
			Tree<Pn> *tree,
			Htab *htab,
			/*DU*/
			_TCHAR* *buf,
			long &start,
			Node<Pn>* &last,
			long &line			// Bookkeep line number.				// 05/17/01 AM.
			);

	inline void DICTTok::nextTok(
			_TCHAR *buf,		// Start char of token.
			long start,		// Start offset of token.
			/*UP*/
			long &end,		// End offset of token.
			_TCHAR* &ptr,		// End char of token.
			enum Pntype &typ,	// Token type.
			bool &lineflag		// Flag new line number.				// 05/17/01 AM.
			);

	inline Sym *DICTTok::internTok(
		_TCHAR *str,				// Ptr to string in a buffer.
		long len,				// Length of string within buffer.
		Htab *htab,				// Hashed symbol table.		// 11/19/98 AM.
		/*UP*/ _TCHAR* &lcstr
		);

	inline bool DICTTok::handleTok(
		Node<Pn> *node,
		Node<Pn> *last,
		enum Pntype typ,
		_TCHAR *str,
		_TCHAR *lcstr
		);

	///////////////////////////////////////
	// The new stuff...

	bool initTok(Parse *parse);
	bool finTok();


	inline bool replaceNum(
		Node<Pn> *node,
		_TCHAR *name,	// variable name.
		long val
		);
	inline bool replaceStr(	// 08/30/08 AM.
		Node<Pn> *node,
		_TCHAR *name,	// variable name.
		_TCHAR *str
		);
	inline _TCHAR *DICTTok::popsval(
		VAL *val
		);

private:
	//Parse *parse;			// The analyze instance that we're tokenizing for.
	bool bad_;					// If unknown char seen.	// 01/15/99 AM.

	// The new stuff...
	
	Parse *parse_;				// Convenience ptr to current parse info.
	Tree<Pn> *tree_;			// The parse tree. (Created in this pass.)
	_TCHAR *text_;				// Start of the input text buffer.
	Htab *htab_;				// Convenience ptr to hash table.

	long topos_;				// "To" position in text buffer.
	long fmpos_;				// "From" position in text buffer.
	_TCHAR *toptr_;			// "To" text buffer pointer.
	_TCHAR *fmptr_;			// "From" text buffer pointer.

	
	long lineno_;				// Track line number in input text buffer.

	Node<Pn> *root_;			// Root node of parse tree.
//	Node<Pn> *page_;			// Current page node.
	Node<Pn> *line_;			// Current line node.
//	Node<Pn> *word_;			// Current word node (if collecting "blobs").
	Node<Pn> *tok_;			// Current literal token node.

	// Track if whitespace was previous token. For NOSP attr.	// 08/16/11 AM.
	bool prevwh_;				// If prev token was whitespace.		// 08/16/11 AM.

	// Count lines and tabs preceding a token.	// 08/16/11 AM.
	long lines_;   // 08/16/11 AM.
	long tabs_;    // 08/16/11 AM.

	// DICTOKZ variant.	Same, but ZAP WHITESPACE (don't put
	// whitespace into the parse tree.)          // 08/16/11 AM.
	bool zapwhite_;         // 08/16/11 AM.

	long totlines_;	// Count lines in text.
	long tottabs_;		// Count tabs in text.
	long totlowers_;	// Count lowercase words.
	long totcaps_;		// Count capitalized words.
	long totuppers_;	// Count uppercase words.
	long totnums_;    // Count numbers.

	//////////////////////////////////////////
	// Miscellaneous.
	_TCHAR buf_[MAXLINE];	// Temporary buffer.
	_TCHAR *ptr_;					// Temporary pointer into buffer.

	// For knowledge base lookup.
	CG *cg_;
};


#endif
