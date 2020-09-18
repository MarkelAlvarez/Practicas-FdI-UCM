package extra.json;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

import org.json.*;

public class UsageExample {

	/* A string with a JSON structure to be used in the examples*/
	static String jsonString = "{ \"a\": 1234, \"b\": 2e-10, \"c\": \"Hola!\", \"d\": [1,2,3], \"e\": { \"k\" : 123,  \"h\" : \"Helloooo!\", \"f\": 23.3e-10 }}";

	/**
	 * Accessing the elements of a JSONObject.
	 */
	static public void accessExample(JSONObject jo) {

		System.out.println("==============================");
		System.out.println("Accessing a JSONObject Example");
		System.out.println("==============================");
		System.out.println();

		/*We can print all keys like in a MAP*/
		System.out.println();
		System.out.println("** Printing keys");
		System.out.println();

		for (String key : jo.keySet())
		{
			System.out.println("-> " + key);
		}

		/*You can ask if it has a key*/
		System.out.println();
		System.out.println("** Check is a key is defined");
		System.out.println();

		if (jo.has("a"))
		{
			System.out.println("It has a key 'a'!!");
		}
		else
		{
			System.out.println("It does not have a key 'a'!!");
		}

		if (jo.has("bla"))
		{
			System.out.println("It has a key 'bla'!!");
		}
		else
		{
			System.out.println("It does not have a key 'bla'!!");
		}

		/* Accessing the value of a key of a known type, already converted to a specific
		 * type (it simple uses casting!). It throws an exception if the type does not
		 * match -- usually you know what type you expect.
		 */
		System.out.println();
		System.out.println("** Check is a key is defined");
		System.out.println();

		System.out.println("a = " + jo.getInt("a"));
		System.out.println("b = " + jo.getDouble("b"));
		System.out.println("c = " + jo.getString("c"));

		/*Array values are special!*/
		System.out.println();
		System.out.println("** Access and traverse array values");
		System.out.println();

		JSONArray ja = jo.getJSONArray("d");
		for (int i = 0; i < ja.length(); i++)
		{
			System.out.println(ja.getInt(i)); // We know the elements are Int
		}

		/*Nested JSON Objects*/
		System.out.println();
		System.out.println("** Access a JSON structure value");
		System.out.println();

		JSONObject jo2 = jo.getJSONObject("e");
		for (String key : jo2.keySet())
		{
			System.out.println("-> " + key);
		}
	}

	/**
	 * Create a JSONObject and fill it with key-value attributes
	 */
	private static void createExample() {

		System.out.println("=============================");
		System.out.println("Creating a JSONObject Example");
		System.out.println("=============================");
		System.out.println();

		JSONObject jo1 = new JSONObject();

		/*We put some keys with simple values into 'jo1'*/
		jo1.put("a", 1234);
		jo1.put("b", 123.3e-10);
		jo1.put("c", "Hollaaa");

		/*We put an array into 'jo1', the elements of the array*/
		JSONArray ja = new JSONArray();
		ja.put(123.34);
		ja.put(3.23);
		ja.put(4.234);
		jo1.put("d", ja);

		/*We put another JSON into 'jo1'*/
		JSONObject jo2 = new JSONObject();

		/*We put some keys with simple values into 'jo2', and the 'jo2' into 'jo1'*/
		jo2.put("g", 1234);
		jo2.put("h", "Hollaaa");
		jo1.put("data", jo2);

		/*Print it*/
		System.out.println(jo1);
		System.out.println();

		/*Print nicely*/
		System.out.println(jo1.toString(2));
		System.out.println();
	}

	/* Check if two JSON structure are semantically equal: have same keys with same
	 * values (order is not important)
	 */
	private static String checkSemanticEquality(JSONObject jo1, JSONObject jo2) {
		
		return jo1.similar(jo2) ? "Yes" : "No";
	}

	public static void main(String[] args) throws JSONException, FileNotFoundException {

		/*Example 1: Parse JSON from a string or from a file*/
		/*Build a JSONObject from a string*/
		JSONObject joFromString = new JSONObject(jsonString);
		
		/*Build a JSONObject from a file*/
		JSONObject joFromFile1 = new JSONObject(
				new JSONTokener(new FileInputStream(new File("resources/other/json-example-1.json"))));
		JSONObject joFromFile2 = new JSONObject(
				new JSONTokener(new FileInputStream(new File("resources/other/json-example-2.json"))));
		JSONObject joFromFile3 = new JSONObject(
				new JSONTokener(new FileInputStream(new File("resources/other/json-example-3.json"))));

		accessExample(joFromString);
		accessExample(joFromFile1);
		accessExample(joFromFile2);
		accessExample(joFromFile3);

		/*Example 2: compare two JSON structures*/
		System.out.println();
		System.out.println("=======================");
		System.out.println("Compare JSON structures");
		System.out.println("=======================");
		System.out.println();

		System.out.println("Are joFromString and joFromFile1 euqal? " + checkSemanticEquality(joFromString, joFromFile1));
		System.out.println("Are joFromString and joFromFile2 euqal? " + checkSemanticEquality(joFromString, joFromFile2));
		System.out.println("Are joFromString and joFromFile3 euqal? " + checkSemanticEquality(joFromString, joFromFile3));
		System.out.println();

		/*Example 3: create JSON structure*/
		createExample();
	}
}