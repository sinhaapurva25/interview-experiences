import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;



class Result {

    /*
     * Complete the 'computeParameterValue' function below.
     *
     * The function is expected to return a STRING_ARRAY.
     * The function accepts 2D_STRING_ARRAY sources as parameter.
     */

    public static List<String> computeParameterValue(List<List<String>> sources) {

    Map<String, Integer> dct = new HashMap<>();
    List<String> res = new ArrayList<>();
    
    for (List<String> source: sources) {
        for (String s: source) {
            int idx = 0;
            for (; idx < s.length(); idx++){if (s.charAt(idx) == ':') break;}
            String name = s.substring(0, idx+1);
            String value = s.substring(idx+1);
            if (dct.containsKey(name)){res.set(dct.get(name), value);}
            else {
                dct.put(name, res.size());
                res.add(value);
            }
        }
    }
    return res;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int sourcesRows = Integer.parseInt(bufferedReader.readLine().trim());
        int sourcesColumns = Integer.parseInt(bufferedReader.readLine().trim());

        List<List<String>> sources = new ArrayList<>();

        IntStream.range(0, sourcesRows).forEach(i -> {
            try {
                sources.add(
                    Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                        .collect(toList())
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        List<String> result = Result.computeParameterValue(sources);

        bufferedWriter.write(
            result.stream()
                .collect(joining("\n"))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
