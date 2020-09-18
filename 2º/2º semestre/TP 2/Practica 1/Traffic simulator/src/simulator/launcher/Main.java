package simulator.launcher;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.*;

import org.apache.commons.cli.CommandLine;
import org.apache.commons.cli.CommandLineParser;
import org.apache.commons.cli.DefaultParser;
import org.apache.commons.cli.HelpFormatter;
import org.apache.commons.cli.Option;
import org.apache.commons.cli.Options;
import org.apache.commons.cli.ParseException;

import simulator.control.Controller;
import simulator.factories.*;
import simulator.model.*;

public class Main {

	private final static Integer _timeLimitDefaultValue = 10;
	private static String _inFile = null;
	private static String _outFile = null;
	private static Factory<Event> _eventsFactory = null;
	private static Integer ticks = 10;

	private static void parseArgs(String[] args) {

		/*Define the valid command line options*/
		Options cmdLineOptions = buildOptions();

		/*Parse the command line as provided in args*/
		CommandLineParser parser = new DefaultParser();

		try {
			CommandLine line = parser.parse(cmdLineOptions, args);
			parseHelpOption(line, cmdLineOptions);
			parseInFileOption(line);
			parseOutFileOption(line);
			parseTicks(line);

			/* If there are some remaining arguments, then something 
			 * wrong is provided in the command line!
			 */
			String[] remaining = line.getArgs();

			if (remaining.length > 0)
			{
				String error = "Illegal arguments:";
				for (String o : remaining)
					error += (" " + o);
				throw new ParseException(error);
			}
		} catch (ParseException e) {
			System.err.println(e.getLocalizedMessage());
			System.exit(1);
		}
	}

	private static Options buildOptions() {

		Options cmdLineOptions = new Options();

		cmdLineOptions.addOption(Option.builder("i").longOpt("input").hasArg().desc("Events input file").build());
		cmdLineOptions.addOption(Option.builder("o").longOpt("output").hasArg().desc("Output file, where reports are written.").build());
		cmdLineOptions.addOption(Option.builder("h").longOpt("help").desc("Print this message").build());
		cmdLineOptions.addOption(Option.builder("t").longOpt("ticks").hasArg().desc("Ticks to the simulator's loop.").build());
		
		return cmdLineOptions;
	}

	private static void parseHelpOption(CommandLine line, Options cmdLineOptions) {

		if (line.hasOption("h"))
		{
			HelpFormatter formatter = new HelpFormatter();
			formatter.printHelp(Main.class.getCanonicalName(), cmdLineOptions, true);
			System.exit(0);
		}
	}

	private static void parseInFileOption(CommandLine line) throws ParseException {

		_inFile = line.getOptionValue("i");
		if (_inFile == null)
		{
			throw new ParseException("An events file is missing");
		}
	}

	private static void parseOutFileOption(CommandLine line) throws ParseException {

		_outFile = line.getOptionValue("o");
	}
	
	private static void parseTicks(CommandLine line) {
		
		if (line.hasOption("t"))
		{
			ticks = Integer.parseInt(line.getOptionValue("t"));
		}
	}

	private static void initFactories() {
	
		List<Builder<LightSwitchingStrategy>> lsbs = new ArrayList<>();
		lsbs.add(new RoundRobinStrategyBuilder());
		lsbs.add(new MostCrowdedStrategyBuilder());
		Factory<LightSwitchingStrategy> lssFactory = new BuilderBasedFactory<>(lsbs);
		
		List<Builder<DequeuingStrategy>> dqbs = new ArrayList<>();
		dqbs.add(new MoveFirstStrategyBuilder());
		dqbs.add(new MoveAllStrategyBuilder());
		Factory<DequeuingStrategy> dqsFactory = new BuilderBasedFactory<>(dqbs);
		
		List<Builder<Event>> ebs = new ArrayList<>();
		ebs.add(new NewJunctionEventBuilder(lssFactory, dqsFactory));
		ebs.add(new NewCityRoadEventBuilder());
		ebs.add(new NewInterCityRoadEventBuilder());
		ebs.add(new NewVehicleEventBuilder());
		ebs.add(new SetWeatherEventBuilder());
		ebs.add(new SetContClassEventBuilder());
		
		_eventsFactory = new BuilderBasedFactory<>(ebs);
	}
	
	private static void startBatchMode() throws IOException {

		OutputStream out;
		InputStream in = new FileInputStream(new File(_inFile));
		TrafficSimulator sim = new TrafficSimulator();
		Controller controller = new Controller(sim, _eventsFactory);
		
		if (_outFile == null)
		{
			out = System.out;
		}
		else
		{
			out = new FileOutputStream(new File(_outFile));
		}
		
		controller.loadEvents(in);
		controller.run(ticks, out);
		in.close();
		out.flush();
		out.close();
	}

	private static void start(String[] args) throws IOException {

		initFactories();
		parseArgs(args);
		startBatchMode();
	}

	/* example command lines:
	 * -i resources/examples/ex1.json
	 * -i resources/examples/ex1.json -t 300
	 * -i resources/examples/ex1.json -o resources/tmp/ex1.out.json
	 * --help
	 */
	public static void main(String[] args) {

		try {
			start(args);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}