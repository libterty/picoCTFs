// password.length() == 32 &&
//                password.charAt(0)  == 'd' &&
//                password.charAt(29) == 'a' &&
//                password.charAt(4)  == 'r' &&
//                password.charAt(2)  == '5' &&
//                password.charAt(23) == 'r' &&
//                password.charAt(3)  == 'c' &&
//                password.charAt(17) == '4' &&
//                password.charAt(1)  == '3' &&
//                password.charAt(7)  == 'b' &&
//                password.charAt(10) == '_' &&
//                password.charAt(5)  == '4' &&
//                password.charAt(9)  == '3' &&
//                password.charAt(11) == 't' &&
//                password.charAt(15) == 'c' &&
//                password.charAt(8)  == 'l' &&
//                password.charAt(12) == 'H' &&
//                password.charAt(20) == 'c' &&
//                password.charAt(14) == '_' &&
//                password.charAt(6)  == 'm' &&
//                password.charAt(24) == '5' &&
//                password.charAt(18) == 'r' &&
//                password.charAt(13) == '3' &&
//                password.charAt(19) == '4' &&
//                password.charAt(21) == 'T' &&
//                password.charAt(16) == 'H' &&
//                password.charAt(27) == '6' &&
//                password.charAt(30) == 'f' &&
//                password.charAt(25) == '_' &&
//                password.charAt(22) == '3' &&
//                password.charAt(28) == 'd' &&
//                password.charAt(26) == 'f' &&
//                password.charAt(31) == '4';

class Main {
  public static void main(String[] args) {
    print();
  }

  private static void print() {
    char[] t = new char[32];
    t[0] = 'd';
    t[29] = 'a';
    t[4] = 'r';
    t[2] = '5';
    t[23] = 'r';
    t[3] = 'c';
    t[17] = '4';
    t[1] = '3';
    t[7] = 'b';
    t[10] = '_';
    t[5] = '4';
    t[9] = '3';
    t[11] = 't';
    t[15] = 'c';
    t[8] = 'l';
    t[12] = 'H';
    t[20] = 'c';
    t[14] = '_';
    t[6] = 'm';
    t[24] = '5';
    t[18] = 'r';
    t[13] = '3';
    t[19] = '4';
    t[21] = 'T';
    t[16] = 'H';
    t[27] = '6';
    t[30] = 'f';
    t[25] = '_';
    t[22] = '3';
    t[28] = 'd';
    t[26] = 'f';
    t[31] = '4';

    String ans = "picoCTF{";

    for (char c : t) {
      ans += c;
    }

    ans += "}";

    System.out.println(ans);
  }
}