
//--------------------------------------------
// File : BitAdjacentMatrix.h
//
// Desc : the Application class for adjacent matrix 
//        using the bit
//
// by xiedonghai, 2004,10.
//--------------------------------------------



//## begin module%418B2B360125.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%418B2B360125.cm

//## begin module%418B2B360125.cp preserve=no
//## end module%418B2B360125.cp

//## Module: BitAdjacentMatrix%418B2B360125; Pseudo Package specification
//## Source file: d:\Program Files\Rational\Rose 98i\C++\source\BitAdjacentMatrix.h

#ifndef BitAdjacentMatrix_h
#define BitAdjacentMatrix_h 1

//## begin module%418B2B360125.additionalIncludes preserve=no
//## end module%418B2B360125.additionalIncludes

//## begin module%418B2B360125.includes preserve=yes
//## end module%418B2B360125.includes

//## begin module%418B2B360125.additionalDeclarations preserve=yes
//## end module%418B2B360125.additionalDeclarations


//## begin BitAdjacentMatrix%418B2B360125.preface preserve=yes
//## end BitAdjacentMatrix%418B2B360125.preface

//## Class: BitAdjacentMatrix%418B2B360125
//	Õâ¸öÀàµÄ×÷ÓÃÊÇ½«ÈıÎ¬Ä£ĞÍµãºÍµãÖ®¼äµÄÁ¬Í¨¹ØÏµ´æ·Åµ½Ò»¸ö
//	bit Îª»ù±¾µ¥ÔªµÄÁ¬Í¨¾ØÕóµ±ÖĞ¡£
//	Éè¾ØÕóÎªM£¬¾ØÕóµÄĞĞÁĞµÄÊıÄ¿ÏàÍ¬£¬¶¼ÊÇµãµÄÊıÄ¿¡£ÉèµãÊıÎª
//	n , ÄÇÃ´¾ØÕóµÄ´óĞ¡Îªn*n.
//	Èç¹ûµã i  Óë µãj ( i, j  )Ö®¼ä´æÔÚÁ¬Í¨¹ØÏµ£¬¾Í½« M[i][j]
//	µÄÖµÉèÖÃÎª1¡£
//	M µÄÃ¿¸öÔªËØ¶¼ÉêÃ÷ÎªÒ»¸öbit¡£
//	ÓÉÓÚc £¬c++ÖĞ×îĞ¡µÄÀàĞÍÎª BYTE,¼´Ò»¸ö×Ö½Ú£¬Õ¼8¸öbitÎ»¡£
//	ÎªÁËÓÃ×Ö½ÚÀ´ÈİÄÉËùÓĞµÄbit£¬ÎÒÃÇĞèÒª½«ĞĞÁĞµÄ³¤¶È×ª»»Îª×Ö½Ú
//	Êı¡£·½·¨ÊÇ£º
//	nBytesOfRow = n / 8 + 1;
//	ĞèÒª·ÖÅäµÄ×Ö½ÚÊıÎª£º  col * nBytesOfRow
//	¿ÉÒÔÍÆµ¼³ö°´Î»´æ·ÅµÄĞĞÁĞ(i ,j )ºÅÓë¶ÔÓ¦µÄ×Ö½ÚµÄ¹ØÏµÎª£º
//
//	 index = i * nBytesOfRow  + j / 8 ;
//
//	ÔÚ×Ö½ÚÖĞµÄÆ«ÒÆÖµÎª j % 8 ;
//
//	Òª×¢ÒâµÄÊÇÆ«ÒÆÖµÊÇ´Ó×óÍùÓÒÊıµÃµ½µÄ¡£
//## Category: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n
#include "stdafx.h"
#include "winnt.h"

class BitAdjacentMatrix 
{
  //## begin BitAdjacentMatrix%418B2B360125.initialDeclarations preserve=yes
  //## end BitAdjacentMatrix%418B2B360125.initialDeclarations

  public:
    //## Constructors (generated)
      BitAdjacentMatrix();

      BitAdjacentMatrix(const BitAdjacentMatrix &right);

    //## Destructor (generated)
      ~BitAdjacentMatrix();

    //## Assignment Operation (generated)
      BitAdjacentMatrix & operator=(const BitAdjacentMatrix &right);

    //## Equality Operations (generated)
      int operator==(const BitAdjacentMatrix &right) const;

      int operator!=(const BitAdjacentMatrix &right) const;


    //## Other Operations (specified)
      //## Operation: SetPos%418B301300EA
      //	¸Ãº¯ÊıµÄ×÷ÓÃÊÇ½«Ò»¸ö×Ö½ÚÖĞÖ¸¶¨µÄÎ»ÖÃÎª1£»
      //	ÆäÔ­ÀíÊÇ£º
      //
      //	1 | 0  =  1;
      //	1 | 1  =  1;
      //	0 | 0  =  0;
      //	0 | 1  =  1;
      //
      //	1 ºÍ 0£¬ 1 µÄ»ò²Ù×÷¶¼Î»1¡£
      //
      //	Ê×ÏÈ¸ù¾İĞĞÁĞºÅÀ´È¡³ö¸Ãµã¶ÔÓ¦µÄ×Ö½Ú a
      //	£¬²¢¼ÆËã³öÆ«ÒÆµÄbitÊı off ¡£
      //	È»ºó½«128 ½øĞĞÓÒÒÆ²Ù×÷£º
      //	 1000 0000   ¡·off
      //	½«1ÒÆµ½ĞèÒª½øĞĞÖÃ1²Ù×÷µÄÎ»ÉÏ¡£
      //
      //	È»ºó¶Ô¸Ã×Ö½Ú½øĞĞÎ»»ò²Ù×÷£¬
      //
      //	a  |=  128 >>off;
      void SetPos (int i, int j);

      //## Operation: IsPosAdjacent%418B305C02CB
      //	¸Ãº¯ÊıµÄ×÷ÓÃÔòÊÇÅĞ¶Ï ĞĞÁĞºÅ ¶ÔÓ¦µÄÎ»ÊÇ·ñÎª1
      //
      //
      //	ÀûÓÃµÄÔ­ÀíÊÇ£º
      //
      //	1 & 1  =  1 ;
      //	1 & 0  =  0 ;
      //
      //	0 & 0 =  0;
      //	0 & 1 =  0;
      //
      //	¹¹ÔìÒ»¸ö×Ö½Ú£¬½«ĞèÒª¼ì²âµÄÄÇ¸öbit Î»ÖÃÎª 1
      //	£¬ÆäËûµÄÉèÖÃÎª0£¬È»ºóÍ¬Ö¸¶¨µÄ×Ö½Ú½øĞĞ Óë²Ù×÷¼´¿É¡£
      //
      //	Ñ°ÕÒ×Ö½ÚºÍÆ«ÒÆÊıÁ¿µÄ·½·¨ºÍ SetPosÊÇÏàÍ¬µÄ¡£
      bool IsPosAdjacent (int i, int j);

      //## Operation: Init%418B319F0074
      //	Î»¾ØÕóµÄ³õÊ¼»¯£¬ĞèÒª¸ù¾İĞĞÁĞµÄ´óĞ¡À´È·¶¨×Ö½ÚÊı£¬È»ºó½«ÉêÇ
//	ëµÄ±äÁ¿È«²¿ÖÃÎª0¡£
      bool Init (LONG wid, LONG hei);

      //## Operation: IsInit%418B7AA9015D
      bool IsInit ();

    // Additional Public Declarations
      //## begin BitAdjacentMatrix%418B2B360125.public preserve=yes
      //## end BitAdjacentMatrix%418B2B360125.public

  protected:
    // Additional Protected Declarations
      //## begin BitAdjacentMatrix%418B2B360125.protected preserve=yes
      //## end BitAdjacentMatrix%418B2B360125.protected

  public:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: m_pBytes%418B2F8A03D3
      const unsigned char* get_m_pBytes () const;
      void set_m_pBytes (unsigned char* value);

      //## Attribute: m_nWid%418B2FC803DF
      const int get_m_nWid () const;
      void set_m_nWid (int value);

      //## Attribute: m_nHei%418B2FD503D7
      const int get_m_nHei () const;
      void set_m_nHei (int value);

      //## Attribute: m_nBytesOfRow%418B5ADE0273
      const int get_m_nBytesOfRow () const;
      void set_m_nBytesOfRow (int value);

    // Additional Private Declarations
      //## begin BitAdjacentMatrix%418B2B360125.private preserve=yes
      //## end BitAdjacentMatrix%418B2B360125.private

  private: //## implementation
    // Data Members for Class Attributes

      //## begin BitAdjacentMatrix::m_pBytes%418B2F8A03D3.attr preserve=no  private: unsigned char* {U} 
      unsigned char* m_pBytes;
      //## end BitAdjacentMatrix::m_pBytes%418B2F8A03D3.attr

      //## begin BitAdjacentMatrix::m_nWid%418B2FC803DF.attr preserve=no  private: int {U} 
      LONG m_nWid;
      //## end BitAdjacentMatrix::m_nWid%418B2FC803DF.attr

      //## begin BitAdjacentMatrix::m_nHei%418B2FD503D7.attr preserve=no  private: int {U} 
      LONG m_nHei;
      //## end BitAdjacentMatrix::m_nHei%418B2FD503D7.attr

      //## begin BitAdjacentMatrix::m_nBytesOfRow%418B5ADE0273.attr preserve=no  private: int {U} 
      LONG m_nBytesOfRow;
      //## end BitAdjacentMatrix::m_nBytesOfRow%418B5ADE0273.attr

    // Additional Implementation Declarations
      //## begin BitAdjacentMatrix%418B2B360125.implementation preserve=yes
      //## end BitAdjacentMatrix%418B2B360125.implementation

};

//## begin BitAdjacentMatrix%418B2B360125.postscript preserve=yes
//## end BitAdjacentMatrix%418B2B360125.postscript

// Class BitAdjacentMatrix 

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned char * BitAdjacentMatrix::get_m_pBytes () const
{
  //## begin BitAdjacentMatrix::get_m_pBytes%418B2F8A03D3.get preserve=no
  return m_pBytes;
  //## end BitAdjacentMatrix::get_m_pBytes%418B2F8A03D3.get
}

inline void BitAdjacentMatrix::set_m_pBytes (unsigned char * value)
{
  //## begin BitAdjacentMatrix::set_m_pBytes%418B2F8A03D3.set preserve=no
  m_pBytes = value;
  //## end BitAdjacentMatrix::set_m_pBytes%418B2F8A03D3.set
}

inline const int BitAdjacentMatrix::get_m_nWid () const
{
  //## begin BitAdjacentMatrix::get_m_nWid%418B2FC803DF.get preserve=no
  return m_nWid;
  //## end BitAdjacentMatrix::get_m_nWid%418B2FC803DF.get
}

inline void BitAdjacentMatrix::set_m_nWid (int value)
{
  //## begin BitAdjacentMatrix::set_m_nWid%418B2FC803DF.set preserve=no
  m_nWid = value;
  //## end BitAdjacentMatrix::set_m_nWid%418B2FC803DF.set
}

inline const int BitAdjacentMatrix::get_m_nHei () const
{
  //## begin BitAdjacentMatrix::get_m_nHei%418B2FD503D7.get preserve=no
  return m_nHei;
  //## end BitAdjacentMatrix::get_m_nHei%418B2FD503D7.get
}

inline void BitAdjacentMatrix::set_m_nHei (int value)
{
  //## begin BitAdjacentMatrix::set_m_nHei%418B2FD503D7.set preserve=no
  m_nHei = value;
  //## end BitAdjacentMatrix::set_m_nHei%418B2FD503D7.set
}

inline const int BitAdjacentMatrix::get_m_nBytesOfRow () const
{
  //## begin BitAdjacentMatrix::get_m_nBytesOfRow%418B5ADE0273.get preserve=no
  return m_nBytesOfRow;
  //## end BitAdjacentMatrix::get_m_nBytesOfRow%418B5ADE0273.get
}

inline void BitAdjacentMatrix::set_m_nBytesOfRow (int value)
{
  //## begin BitAdjacentMatrix::set_m_nBytesOfRow%418B5ADE0273.set preserve=no
  m_nBytesOfRow = value;
  //## end BitAdjacentMatrix::set_m_nBytesOfRow%418B5ADE0273.set
}

//## begin module%418B2B360125.epilog preserve=yes
//## end module%418B2B360125.epilog


#endif
