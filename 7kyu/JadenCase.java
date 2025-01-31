public class JadenCase {
    public String toJadenCase(String phrase) {
        if (phrase == null || phrase == "") {
            return null;
        }

        String result = new String();

        for (String word : phrase.split(" ")) {
            StringBuilder stringBuilder = new StringBuilder(word);

            char upperChar = Character.toUpperCase(word.charAt(0));
            stringBuilder.setCharAt(0, upperChar);

            result += stringBuilder.toString() + " ";
        }

        result = result.substring(0, result.length() - 1); // Pop last char

        return result;
    }
}
