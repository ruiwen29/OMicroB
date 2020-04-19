
import java.io.*;
import java.util.Scanner;
// import Test.clientRead.java;
// import Test.clientWrite.java;
class clientWrite extends Thread  {

    public static void clientWrite() throws IOException {
      //读键盘需要读buffer
      BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
      //读取cmd_pipe
      FileOutputStream FileOutputStream = new FileOutputStream("serverRead");


      //创建输出buffer
      BufferedOutputStream out = new BufferedOutputStream(FileOutputStream);

      //String s = "hello!/n";
      Scanner keyboard = new Scanner(System.in);
      while(true){
      System.out.println("enter sth");
      String str = null;
      str = in.readLine();
      byte[] arr = str.getBytes();
      out.write(arr,0,arr.length);
      out.flush();

      //in.close();
      //out.close();
    }

    }
    public void run()  {
      try{clientWrite();}
      catch(IOException e){e.printStackTrace();}

    }

}

class clientRead extends Thread  {
    private static final String FIFO = "serverWrite";

    public static void clientWrite() throws IOException {

      
      FileInputStream FileInputStream = new FileInputStream("serverWrite");
      BufferedInputStream in = new BufferedInputStream(FileInputStream);

      try {
        //定义缓冲区的字节读取为1024
				 byte[] bytes = new byte[1024];
         int b;
         //read(byte[] b) 这个方法是先规定一个数组长度，将这个流中的字节缓冲到数组b中，返回
         //的这个数组中的字节个数，这个缓冲区没有满的话，则返回真实的字节个数，到未尾时都返回-1
					while((b = in .read(bytes)) != -1){
            String data = new String(bytes, "utf-8");
						System.out.println(data);
					}
				} catch (Exception e) {
					e.printStackTrace();
				}



    }
    public void run()  {
      try{clientWrite();}
      catch(IOException e){e.printStackTrace();}

    }

}

public class client {
    public static void main(String[] args) {
         new clientRead().start();
         new clientWrite().start();
    }
}
