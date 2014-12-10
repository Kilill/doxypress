/*************************************************************************
 *
 * Copyright (C) 1997-2014 by Dimitri van Heesch.
 * Copyright (C) 2008 by Sebastian Pipping.
 * Copyright (C) 2014-2015 Barbara Geller & Ansel Sermersheim 
 * All rights reserved.    
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License version 2
 * is hereby granted. No representations are made about the suitability of
 * this software for any purpose. It is provided "as is" without express or
 * implied warranty. See the GNU General Public License for more details.
 *
 * Documents produced by Doxygen are derivative works derived from the
 * input used in their production; they are not affected by this license.
 *
*************************************************************************/

#ifndef QHPXMLWRITER_H
#define QHPXMLWRITER_H

#include <QString>
#include <QFile>

#include <ftextstream.h>

class QhpXmlWriter
{
 public:
   QhpXmlWriter();
   ~QhpXmlWriter();

   void setIndentLevel(int level);
   void setCompressionEnabled(bool enabled);
   void insert(QhpXmlWriter const &source);
   void dumpTo(QFile &file);
   void open(char const *elementName, char const *const *attributes = 0);
   void openClose(char const *elementName, char const *const *attributes = 0);
   void openCloseContent(char const *elementName, char const *content);
   void close(char const *elementName);
   void declaration(char const *version, char const *encoding);

   static char *dupEscaped(const char *source);

 private:
   void indent();
   void newLine();
   void openPureHelper(char const *elementName,
                       char const *const *attributes, bool close);
   void openPure(char const *elementName,
                 char const *const *attributes = 0);
   void openClosePure(char const *elementName, char const *const *attributes = 0);
   void closePure(char const *elementName);

   QByteArray m_backend;
   FTextStream m_out;
   int  m_indentLevel;
   bool m_curLineIndented;
   bool m_compress;

};

#endif // QHPXMLWRITER_H
