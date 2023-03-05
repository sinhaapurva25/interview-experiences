import scala.util.control.Breaks._
object Main
{

  def main(args: Array[String])
  {
    println(PrimeTime(scala.io.StdIn.readLine()));
  }
   
  // code goes here  
  def PrimeTime(num: Int): String =
  {
    var c = 0
    for (j <- 1 to num)
    {
      if (num%j==0) c = c+1;
      // if (c >= 2) break;
    }
    if (c==2) return "true" else return "false"
  }
}