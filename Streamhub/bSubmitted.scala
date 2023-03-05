object Main {

  def main(args: Array[String]) {
    println(LetterCount(scala.io.StdIn.readLine()));
  }
   
  // code goes here  
  def LetterCount(str: String): String =
  {
    val s = str.split(" ")
    var maxCount = 2
    var v = scala.collection.immutable.Vector()

    for (i <- s)
    {
      var m = scala.collection.mutable.HashMap.empty[String,Int]
      var w = i.split("")
      for (j <- w)
      {
        if (m.contains(j))
          m(j) = m(j)+1
        else
          m.+=((j,1))
      }

      for (j <- m)
      {
        if (j._2 > maxCount)
          maxCount = j._2
      }

    }

    var result = Array.tabulate(s.size)(n => "")
    var count = 0

    for (i <- s)
    {
      var m = scala.collection.mutable.HashMap.empty[String,Int]
      var w = i.split("")
      for (j <- w)
      {
        if (m.contains(j))
          m(j) = m(j)+1
        else
          m.+=((j,1))
      }

      for (j <- m)
      {
        if (j._2 == maxCount)
        {
          result(count) = i
        }
      }
      count += 1
    }
      result = result.filter(p => p!="")

      if (result.size >1)
        return result(0)
      else
        if (result.size == 0)
          return "-1"
        else
          return result(0)
  }

}