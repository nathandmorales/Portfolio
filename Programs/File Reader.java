import java.io.*;
import java.util.ArrayList;
public class HWtiny2 
{
    public static void main(String[] args)throws Exception
    {
        ArrayList<String> lines = new ArrayList<String>();
        ArrayList<String> sent = new ArrayList<String>();
        ArrayList<String> allWords = new ArrayList<String>();
        ArrayList<String> wordsArray = new ArrayList<String>();
        ArrayList<Integer> freqArray = new ArrayList<Integer>();
        File text = new File("C:\\Users\\Black\\Desktop\\data\\data\\tiny2.txt");

        BufferedReader br = new BufferedReader(new FileReader(text));

        String st;
        while((st = br.readLine()) != null)
        {
            lines.add(st);
        }

        for (String t: lines)
        {
            String[] split = t.split(" ");
            for (String t2: split)
            {
                int index = wordsArray.indexOf(t2);
                if (index == -1)
                {
                    wordsArray.add(t2);
                }
                allWords.add(t2);
            }

        }

        for (String t: lines)
        {
            String[] split = t.split("\\.");
            for (String t2: split)
            {
                sent.add(t2);
            }
        }

        for (String t: wordsArray)
        {
            int freq = 0;
            for (String t2: allWords)
            { 
                if (t.equalsIgnoreCase(t2))
                {
                    freq += 1;
                }
            }
            freqArray.add(freq);
        }

        //QUESTION 1-3**********************************************************************************************
        int max = 0;
        int max2 = 0;
        int max3 = 0;
        int maxIndex = 0;
        int max2Index = 0;
        int max3Index = 0;
        
        for (int i = 0; i < freqArray.size(); i++)
        {
            if (freqArray.get(i) > max)
            {
                max = freqArray.get(i);
            }else if ((freqArray.get(i) < max) && (freqArray.get(i) > max2))
            {
                max3 = max2;
                max2 = freqArray.get(i);
            }else if ((freqArray.get(i) < max) && (freqArray.get(i) < max2) && (freqArray.get(i) > max3))
            {
                max3 = freqArray.get(i);
            }

            if (freqArray.get(i) > maxIndex)
            {
                maxIndex = i;
            }else if (freqArray.get(i) > max2Index)
            {
                max2Index = i;
            }else if (freqArray.get(i) > max3Index)
            {
                max3Index = i;
            }
        }
        System.out.println(wordsArray.get(maxIndex) + ":" + max);
        System.out.println(wordsArray.get(max2Index) + ":" + max2);
        System.out.println(wordsArray.get(max3Index) + ":" + max3);

        int maxFreq = 0;
        String maxLine = " ";
        String maxWord = " ";
        for (String t: sent)
        {
            int tempFreq = 0;
            String[] splitSent = t.split(" ");
            for (String t2: wordsArray)
            {
                for (String t3: splitSent)
                {
                    if (t2.equalsIgnoreCase(t3))
                    {
                        tempFreq += 1;
                    }
                }
                if (tempFreq > maxFreq)
                {
                    maxFreq = tempFreq;
                    maxLine = t;
                    maxWord = t2;
                }
                tempFreq = 0;
            }
        }
        System.out.println(maxWord + ":" + maxFreq + ":" + maxLine);

        int ofFreq = 0;
        String ofSent = " ";
        for (String t: sent)
        {
            int tempFreq = 0;
            String[] splitSent = t.split(" ");
            for (String t2: splitSent)
            {
                if (t2.equalsIgnoreCase("of"))
                {
                    tempFreq += 1;
                }
            }
            if (tempFreq > ofFreq)
            {
                ofFreq = tempFreq;
                ofSent = t;
            }
        }
        System.out.println("of:" + ofFreq + ":" + ofSent);



        int wasFreq = 0;
        String wasSent = " ";
        for (String t: sent)
        {
            int tempFreq = 0;
            String[] splitSent = t.split(" ");
            for (String t2: splitSent)
            {
                if (t2.equalsIgnoreCase("was"))
                {
                    tempFreq += 1;
                }
            }
            if (tempFreq > wasFreq)
            {
                wasFreq = tempFreq;
                wasSent = t;
            }
        }
        System.out.println("was:" + wasFreq + ":" + wasSent);

        ArrayList<Integer> btFreqArray = new ArrayList<Integer>();
        ArrayList<String> btSentArray = new ArrayList<String>();
        int btFreq = 0;
        String btSent = " ";
        for (String t: sent)
        {
            int tempFreq = 0;
            String[] splitSent = t.split(" ");
            for (int i = 0; i < splitSent.length; i++)
            {
                if ((splitSent[i].equalsIgnoreCase("but")) && (splitSent[i + 1].equalsIgnoreCase("the")))
                {
                    tempFreq += 1;
                }
            }
            if (tempFreq >= btFreq)
            {
                btFreq = tempFreq;
                btSent = t;
                btFreqArray.add(btFreq);
                btSentArray.add(btSent);
            }
        }

        for (int i = 0; i < btFreqArray.size(); i++)
        {
            System.out.println("but the:" + btFreqArray.get(i) + ":" + btSentArray.get(i));
        }

        ArrayList<Integer> iwFreqArray = new ArrayList<Integer>();
        ArrayList<String> iwSentArray = new ArrayList<String>();
        int iwFreq = 0;
        String iwSent = " ";
        for (String t: sent)
        {
            int tempFreq = 0;
            String[] splitSent = t.split(" ");
            for (int i = 0; i < splitSent.length; i++)
            {
                if ((splitSent[i].equalsIgnoreCase("it")) && (splitSent[i + 1].equalsIgnoreCase("was")))
                {
                    tempFreq += 1;
                }
            }
            if (tempFreq > iwFreq)
            {
                iwFreq = tempFreq;
                iwSent = t;
                iwFreqArray.add(iwFreq);
                iwSentArray.add(iwSent);
            }
        }
        
        for (int i = 0; i < iwFreqArray.size(); i++)
        {
            System.out.println("it was:" + iwFreqArray.get(i) + ":" + iwSentArray.get(i));
        }

        ArrayList<Integer> imFreqArray = new ArrayList<Integer>();
        ArrayList<String> imSentArray = new ArrayList<String>();
        int imFreq = 0;
        String imSent = " ";
        for (String t: sent)
        {
            int tempFreq = 0;
            String[] splitSent = t.split(" ");
            for (int i = 0; i < splitSent.length; i++)
            {
                if ((splitSent[i].equalsIgnoreCase("in")) && (splitSent[i + 1].equalsIgnoreCase("my")))
                {
                    tempFreq += 1;
                }
            }
            if (tempFreq >= imFreq)
            {
                imFreq = tempFreq;
                imSent = t;
                imFreqArray.add(imFreq);
                imSentArray.add(imSent);
            }
        }

        for (int i = 0; i < imFreqArray.size(); i++)
        {
            System.out.println("in my:" + imFreqArray.get(i) + ":" + imSentArray.get(i));
        }









        FileWriter q1;
        FileWriter q2;
        FileWriter q3;
        FileWriter q4;
        FileWriter q5;
        FileWriter q6;
        FileWriter q7;
        FileWriter q8;
        FileWriter q9;
        try
        {
            q1 = new FileWriter("tiny2_1");
            q2 = new FileWriter("tiny2_2");
            q3 = new FileWriter("tiny2_3");
            q4 = new FileWriter("tiny2_4");
            q5 = new FileWriter("tiny2_5");
            q6 = new FileWriter("tiny2_6");
            q7 = new FileWriter("tiny2_7");
            q8 = new FileWriter("tiny2_8");
            q9 = new FileWriter("tiny2_9");

            BufferedWriter bw1 = new BufferedWriter(q1);
            BufferedWriter bw2 = new BufferedWriter(q2);
            BufferedWriter bw3 = new BufferedWriter(q3);
            BufferedWriter bw4 = new BufferedWriter(q4);
            BufferedWriter bw5 = new BufferedWriter(q5);
            BufferedWriter bw6 = new BufferedWriter(q6);
            BufferedWriter bw7 = new BufferedWriter(q7);
            BufferedWriter bw8 = new BufferedWriter(q8);
            BufferedWriter bw9 = new BufferedWriter(q9);

            bw1.write(wordsArray.get(maxIndex) + ":" + max);
            bw2.write(wordsArray.get(max3Index) + ":" + max3);
            bw3.write(maxWord + ":" + maxFreq + ":" + maxLine);
            bw4.write(maxWord + ":" + maxFreq + ":" + maxLine);
            bw5.write("of:" + ofFreq + ":" + ofSent);
            bw6.write("was:" + wasFreq + ":" + wasSent);  
            for (int i = 0; i < btFreqArray.size(); i++)
            {
                bw7.write("but the:" + btFreqArray.get(i) + ":" + btSentArray.get(i));
                bw7.newLine();
            }
            for (int i = 0; i < iwFreqArray.size(); i++)
            {
                bw8.write("it was:" + iwFreqArray.get(i) + ":" + iwSentArray.get(i));
                bw8.newLine();
            }
            for (int i = 0; i < imFreqArray.size(); i++)
            {
                bw9.write("in my:" + imFreqArray.get(i) + ":" + imSentArray.get(i));
                bw9.newLine();
            }

            bw1.close();
            bw2.close();
            bw3.close();
            bw4.close();
            bw5.close();
            bw6.close();
            bw7.close();
            bw8.close();
            bw9.close();
        }
        catch (IOException excpt)
        {
            excpt.printStackTrace();
        }
    }
}