import java.util.ArrayList;
import java.util.Collections;

public class GenRand {
    public static void main(String[] args) {
        try {
            if (args.length > 1) {
                System.out.print("Error. Incorrect start.");
                System.exit(-1);
            }
            int countNum = Integer.parseInt(args[0]);
            ArrayList<Integer> generated = new ArrayList<Integer>();
            while (countNum != 0) {
                generated.add(countNum--);
            }
            Collections.shuffle(generated);
            for (int num : generated) {
                System.out.print(num + " ");
            }
        } catch (Exception e) {
            System.out.print("Error. Incorrect start.");
        }
    }
}
