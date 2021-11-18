import java.io.*;
public class HW4 {
    static void towerofHanoi_3(int disk, char from, char to, char spare, StringBuilder ans)
    {
        if (disk == 1)
        {
            ans.append(disk + " " + from + " " + to + "\n");
            return;
        }
        else 
        {
            towerofHanoi_3(disk - 1, from, spare, to, ans);
            ans.append(disk + " " + from + " " + to + "\n");
            towerofHanoi_3(disk - 1, spare, to, from, ans);
        }
    }

    static void towerofHanoi_4(int disk, char from, char to, char spare, char spare2, StringBuilder ans)
    {
        if (disk == 0) 
        {
            return;
        }
        if (disk == 1)
        {
            ans.append(disk + " " + from + " " + to + "\n");
            return;
        }
        else 
        {
            towerofHanoi_4(disk - 2, from, spare, spare2, to, ans);
            ans.append(disk - 1 + " " + from + " " + spare2 + "\n");
            ans.append(disk + " " + from + " " + to + "\n");
            ans.append(disk - 1 + " " + spare2 + " " + to + "\n");
            towerofHanoi_4(disk - 2, spare, to, from, spare2, ans);
        }
    }

    static void towerofHanoi_5(int disk, char from, char to, char spare, char spare2, char spare3, StringBuilder ans)
    {
        if (disk == 0)
        {
            return; 
        }
        if (disk == 1)
        {
            ans.append(disk + " " + from + " " + to + "\n");
            return;
        }
        if (disk == 2)
        {
            ans.append(disk - 1 + " " + from + " " + spare + "\n");
            ans.append(disk + " " + from + " " + to + "\n");
            ans.append(disk - 1 + " " + spare + " " + to + "\n");
            return;
        }
        else 
        {
            towerofHanoi_5(disk - 3, from, spare, spare2, spare3, to, ans);
            ans.append(disk - 2 + " " + from + " " + spare3 + "\n");
            ans.append(disk - 1 + " " + from + " " + spare2 + "\n");
            ans.append(disk + " " + from + " " + to + "\n");
            ans.append(disk - 1 + " " + spare2 + " " + to + "\n");
            ans.append(disk - 2 + " " + spare3 + " " + to + "\n");
            towerofHanoi_5(disk - 3, spare, to, from, spare2, spare3, ans);
        }
    }

    public static void main(String[] args)throws Exception
    {
        StringBuilder ans = new StringBuilder();
        FileWriter fw = new FileWriter(args[2]);
        BufferedWriter bw = new BufferedWriter(fw);

        int disks = Integer.parseInt(args[1]);
        if (args[0] == "3")
        {
            towerofHanoi_3(disks, 'A', 'C', 'B', ans);
        }else if (args[0] == "4")
        {
            towerofHanoi_4(disks, 'A', 'D', 'B', 'C', ans);
        }else if (args[0] == "5")
        {
            towerofHanoi_5(disks, 'A', 'E', 'B', 'C', 'D', ans);
        }
        
        bw.write(ans.toString());
        bw.close();
    }
}
