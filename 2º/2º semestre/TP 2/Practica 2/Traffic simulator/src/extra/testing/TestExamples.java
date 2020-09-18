package extra.testing;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import org.json.JSONTokener;

public class TestExamples {

	static PrintStream _stdOut = System.out;
	static PrintStream _stdErr = System.err;

	static PrintStream nullStream = new PrintStream(new OutputStream() {

		@Override
		public void write(int b) throws IOException {
		}
	});

	public static void start(String path, boolean testMode) throws JSONException, FileNotFoundException {

		JSONObject jo = new JSONObject(new JSONTokener(new FileInputStream(new File(path + "/db.json"))));

		JSONArray tests = jo.getJSONArray("tests");

		if (testMode)
		{
			System.setOut(nullStream);
			System.setErr(nullStream);
			for (int i = 0; i < tests.length(); i++)
			{
				test(path, tests.getJSONObject(i));
			}
		}
		else
		{
			for (int i = 0; i < tests.length(); i++)
			{
				run(path, tests.getJSONObject(i));
			}
		}
	}

	private static void run(String path, JSONObject info) {
		
		String inFile = path + "/" + info.getString("file") + ".json";
		String outFile = path + "/" + info.getString("file") + ".expout.json";
		Integer ticks = info.getInt("ticks");

		System.out.println("-> Running: " + inFile);

		try {
			simulator.launcher.Main.main(new String[] { "-i", inFile, "-o", outFile, "-t", ticks.toString() });
			System.out.println("OK!");
		} catch (Exception e) {
			System.out.println("Failed (exception thrown).");
		}
	}

	private static void test(String path, JSONObject info) {
		
		File inFile = new File(path + "/" + info.getString("file") + ".json");
		File outFile = new File(path + "/" + info.getString("file") + ".expout.json");
		File myoutFile = new File(path + "/" + info.getString("file") + ".myout.json");
		Integer ticks = info.getInt("ticks");

		_stdOut.println("-> Running: " + inFile);
		
		try {
			simulator.launcher.Main.main(new String[] { "-i", inFile.getPath(), "-o", myoutFile.getPath(), "-t", ticks.toString() });

			JSONObject jo1 = new JSONObject(new JSONTokener(new FileInputStream(outFile)));
			JSONObject jo2 = new JSONObject(new JSONTokener(new FileInputStream(myoutFile)));

			if (jo1.similar(jo2))
			{
				_stdOut.println("OK!");
				myoutFile.delete(); //Delete the file
			}
			else
			{
				_stdOut.println("Failed (output is not equal)!");
			}
		} catch (Exception e) {
			_stdOut.println("Failed (exception thrown).");
		}

	}

	/* The full path to the examples directory, where db.json is, should be passed
	 * as the first command-line argument. If not passed it looks in the default
	 * examples directory "resources/examples"
	 */
	public static void main(String[] args) throws JSONException, FileNotFoundException {
		
		String path = args.length == 0 ? "resources/examples" : args[0];
		// change 'true' to 'false' to generate the expected output instead of testing
		start(path, true);
	}
}