import java.io.*;
import java.util.ArrayList;

public class HW2
{
    static class Node 
    {
        float data;
        int row;
        int col;
        Node right;
        Node down;

        Node(){
            this.data = 0;
            this.row = 0;
            this.col = 0;
            Node right = null;
            Node down = null;
        }

        public int getRow()
        {
            return row;
        }

        public int getCol()
        {
            return col;
        }
    };

    static Node constructLinkedList(int arr[][], int i, int j, int row, int col) 
    { 
        if (i > row - 1 || j > col - 1)
        { 
            return null; 
        }
 
        Node temp = new Node(); 
        temp.data = arr[i][j]; 
        temp.row = row;
        temp.col = col;
        temp.right = constructLinkedList(arr, i, j + 1, row, col); 
        temp.down = constructLinkedList(arr, i + 1, j, row, col); 
        return temp; 
    } 

    //WORKS
    static Node fileRead(String fname) throws IOException
    {
        File m1 = new File(fname); 
        BufferedReader br = new BufferedReader(new FileReader(m1));

        ArrayList<String[]> ml = new ArrayList<String[]>();

        String line;
        int mlRow = 0;
        int mlCol = 0;
        while((line = br.readLine()) != null)
        {   
            String[] splitLine = line.split(" ");
            mlCol = splitLine.length;
            ml.add(splitLine);
            mlRow++;
        }

        int[][] tempM = new int[mlRow][mlCol];

        for (int i = 0; i < ml.size(); i++)
        {
            for (int j = 0; j < ml.size(); j++)
            {
                tempM[i][j] = Integer.parseInt(ml.get(i)[j]);
            }
        }
        Node matrix = constructLinkedList(tempM, 0, 0, mlRow, mlCol);
        mlRow = 0;
        mlCol = 0;
        ml.clear();
        br.close();
        return matrix;
    }

    static void display(Node head, String fileOut) throws IOException
    { 
        FileWriter out = new FileWriter(fileOut);
        BufferedWriter bw = new BufferedWriter(out);
        Node Rp; 
        Node Dp = head; 
   
        while (Dp != null) 
        { 
            Rp = Dp; 
   
            while (Rp != null) 
            { 
                bw.write(Rp.data + " "); 
                Rp = Rp.right; 
            } 
            bw.write("\n"); 
            Dp = Dp.down; 
        } 
        bw.close();
    } 

    static void printMatrix(Node head)
    { 
        Node Rp; 
        Node Dp = head; 
   
        while (Dp != null) 
        { 
            Rp = Dp; 
   
            while (Rp != null) 
            { 
                System.out.print(Rp.data + " "); 
                Rp = Rp.right; 
            } 
            System.out.println(); 
            Dp = Dp.down; 
        } 
    } 

    public static Node add(Node m, Node m2) 
    {
        Node rp1;
        Node dp1 = m;
        Node rp2;
        Node dp2 = m2;
        float f;

        if (dp1.getCol() == dp2.getCol() && dp1.getRow() == dp2.getCol())
        {
            int[][] tempMatrix = new int[dp1.getRow()][dp1.getCol()];
            Node matSum = constructLinkedList(tempMatrix, 0, 0, dp1.getRow(), dp1.getCol());
            Node tempRp;
            Node tempDp = matSum;

            while (dp1 != null)
            {
                rp1 = dp1;
                rp2 = dp2;
                tempRp = tempDp;
                while (rp1 != null)
                {
                    f = rp1.data + rp2.data;
                    tempRp.data = f;
                    tempRp = tempRp.right;
                    rp1 = rp1.right;
                    rp2 = rp2.right;
                }
                dp1 = dp1.down;
                dp2 = dp2.down;
                tempDp = tempDp.down;
            }
            return matSum;
        }else 
        {
            return null;
        }
    }

    public static Node sub(Node m, Node m2) 
    {
        Node rp1;
        Node dp1 = m;
        Node rp2;
        Node dp2 = m2;
        float f;

        if (dp1.getCol() == dp2.getCol() && dp1.getRow() == dp2.getCol())
        {
            int[][] tempMatrix = new int[dp1.getRow()][dp1.getCol()];
            Node matSum = constructLinkedList(tempMatrix, 0, 0, dp1.getRow(), dp1.getCol());
            Node tempRp;
            Node tempDp = matSum;

            while (dp1 != null)
            {
                rp1 = dp1;
                rp2 = dp2;
                tempRp = tempDp;
                while (rp1 != null)
                {
                    f = rp1.data - rp2.data;
                    tempRp.data = f;
                    tempRp = tempRp.right;
                    rp1 = rp1.right;
                    rp2 = rp2.right;
                }
                dp1 = dp1.down;
                dp2 = dp2.down;
                tempDp = tempDp.down;
            }
            return matSum;
        }else 
        {
            return null;
        }
    }

    /*
    public static Node multiply(Node m, Node m2) 
    {
        Node rp1 = m;
        Node dp1;
        Node rp2 = m2;
        Node dp2;
        float f = 0;

        if (rp1.getCol() == rp2.getRow())
        {
            int[][] tempMatrix = new int[rp1.getRow()][rp2.getCol()];
            Node matSum = constructLinkedList(tempMatrix, 0, 0, rp1.getRow(), rp2.getCol());
            Node tempRp;
            Node tempDp = matSum;

            while (rp1 != null)
            {
                dp1 = rp1;
                dp2 = rp2;
                tempRp = tempDp;
                while (dp2 != null)
                {
                    f += rp1.data * dp2.data;
                    rp1 = rp1.right;
                    dp2 = dp2.down;
                }
                tempRp.data = f;
                tempRp = tempRp.right;
                f = 0;
                dp1 = dp1.down;
                dp2 = rp2.right;
                tempDp = tempDp.down;
            }
            return matSum;
        }else 
        {
            return null;
        }
    }
    
    /*
    public static Node transpose(Node m) 
    {
        Node rp = m;
        Node dp;
        float f = 0;
        int[][] tempMatrix = new int[m.getCol()][m.getRow()];
        Node matSum = constructLinkedList(tempMatrix, 0, 0, m.getCol(), m.getRow());
        Node tempRp;
        Node tempDp = matSum;

        while (rp != null)
        {
            dp = rp;
            tempRp = tempDp;
            while (dp != null)
            {
                f = rp.data;
                tempDp.data = f;
                tempDp = tempDp.down;
                dp = dp.down;
            }
            rp = rp.right;
            tempRp = tempRp.right;
        }
        return matSum;
    }

    /*
    static Int determinant(Node m)
    {

    }
    */

    public static void main(String[] args) throws IOException
    {
        
        if (args.length == 4)
        {
            Node m1 = fileRead(args[1]);
            Node m2 = fileRead(args[2]);
        }else 
        {
            Node m1 = fileRead(args[1]);
        }
        
        if (args[0] == "add")
        {
            Node ans = add(m1, m2);
            display(ans, args[3]);
        }else if (args[0] == "sub")
        {
            Node ans = sub(m1, m2);
            display(ans, args[3]);
        }else if (args[0] == "mul")
        {
            Node ans = multiply(m1, m2);
            display(ans, args[3]);
        }else if (args[0] == "tra")
        {
            Node ans = transpose(m1);
            display(ans, args[3]);
        }else if (args[0] == "det")
        {
            
        }
        
    }
}