import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.io.IOException;

public class CPTTRN1 {
    public static void main(String args[]) {
        try
        {
            boolean first = true;
            int t = 0; // The number of test cases
            ArrayList<Integer> values = new ArrayList<Integer>();

            StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
            int token;
            while ((token = st.nextToken()) != StreamTokenizer.TT_EOF)
            {
                switch (token)
                {
                    case StreamTokenizer.TT_NUMBER:
                        if (first) {
                            first = false;
                            t = (int) st.nval;
                        } else {
                            values.add((int) st.nval);
                        }
                        break;
                }
            }

            int rowCounter = 0;
            int colCounter = 0;
            for (int i = 0; i < t; i++) {
                for (int j = 0; j < values.get(i * 2); j++) {
                    colCounter = rowCounter;
                    for (int z = 0; z < values.get((i * 2) + 1); z++) {
                        if (colCounter == 0) {
                            System.out.print("*");
                        } else {
                            System.out.print(".");
                        }
                        colCounter = ~colCounter;
                    }

                    rowCounter = ~rowCounter;
                    System.out.println("");
                }
                if (i != (t - 1)) {
                    System.out.println("");
                }
                rowCounter = 0;
                colCounter = 0;
            }

        } catch(IOException io) {
            return;
        }	
    }
}
