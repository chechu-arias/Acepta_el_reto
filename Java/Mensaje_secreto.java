import java.util.Scanner;

public class Mensaje_secreto {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        while(sc.hasNextLine()) {
            String line = sc.nextLine();
            int c = 0;
            int pos = 0;
            String res = "";
            while(pos < line.length()) {
                try {
                    c = Integer.parseInt(line.substring(pos, pos+3));
                } catch (Exception e) {
                    c = Integer.parseInt(line.substring(pos, pos+2));
                }
                
                if (c < 150) {
                    res += (char)c;
                    pos += 3;
                } else {
                    c = Integer.parseInt(line.substring(pos, pos+2));
                    res += (char)c;
                    pos += 2;
                }

            }

            System.out.println(res);

        }
        sc.close();
    }

}