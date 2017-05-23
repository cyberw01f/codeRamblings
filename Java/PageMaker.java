// Copyright (c) 2017 Abhineet Dubey. All rights reserved.
// Use of this source code is governed by the GPLv3 license that can be
// found in the LICENSE file.
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

class PageMaker {

  public static void main(String[] args) throws IOException {

      PrintWriter pw = new PrintWriter (new FileWriter("Startpage.html"));
      Scanner sc = new Scanner(System.in);
      pw.println("<Table><TR><TH>Websites<TH>Link</TR>");
        for (int i = 0; i <= 10 ; i++) {
            String s = sc.next();
            pw.format("<TR ALIGN=RIGHT><TD>%d<TD>%.1f%s", i, s);
        }
        pw.println("</TABLE>");
        pw.close();

  }

}
