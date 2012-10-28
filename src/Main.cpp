
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <tr1/memory>
#include "../include/OpenShot.h"

using namespace openshot;
using namespace tr1;

void FrameReady(int number)
{
	cout << "Frame #: " << number << " is ready!" << endl;
}

int main()
{
//	// Create timeline
//	Timeline t(640, 360, Framerate(24,1));
//
//	// Add some clips
//	Clip c1(new FFmpegReader("/home/jonathan/Videos/sintel_trailer-720p.mp4"));
//	c1.Position(0.0);
//
//	// LINEAR Reverse
//	//c1.time.AddPoint(1, 500, LINEAR);
//	//c1.time.AddPoint(500, 1, LINEAR);
//
//	// LINEAR Slow Reverse (sounds wavy, due to periodic repeated frames)
//	//c1.time.AddPoint(1, 500, LINEAR);
//	//c1.time.AddPoint(500, 100, LINEAR);
//
//	// LINEAR Slow Reverse X2 (smooth)
//	c1.time.AddPoint(1, 500, LINEAR);
//	c1.time.AddPoint(500, 250, LINEAR);
//
//	// LINEAR Fast Reverse (sounds wavy, due to periodic repeated frames)
//	//c1.time.AddPoint(1, 600, LINEAR);
//	//c1.time.AddPoint(500, 1, LINEAR);
//
//	// LINEAR Slow Forward
//	//c1.time.AddPoint(1, 1000, LINEAR);
//	//c1.time.AddPoint(500, 1, LINEAR);
//
////	// BEZIER Reverse
////	openshot::Point p1(1,500);
////	p1.handle_left = Coordinate(1,500);
////	p1.handle_right = Coordinate(250,500);
////
////	openshot::Point p2(500,100);
////	p1.handle_left = Coordinate(500,350);
////	p1.handle_right = Coordinate(500,100);
////
////	c1.time.AddPoint(p1);
////	c1.time.AddPoint(p2);
//
////	c1.time.AddPoint(1, 500, LINEAR);
////	c1.time.AddPoint(500, 1, LINEAR);
////	c1.time.AddPoint(1, 500, LINEAR);
////	c1.time.AddPoint(200, 200);
////	c1.time.AddPoint(500, 500, LINEAR);
//	c1.time.PrintValues();
//
//	// Add clips
//	t.AddClip(&c1);
//
//
//	// Create a writer
//	FFmpegWriter w("/home/jonathan/output.webm");
//	w.DisplayInfo();
//
//	// Set options
//	//w.SetAudioOptions(true, "libmp3lame", 44100, 2, 128000, false);
//	w.SetAudioOptions(true, "libvorbis", 44100, 2, 128000, false);
//	w.SetVideoOptions(true, "libvpx", Fraction(24, 1), 640, 360, Fraction(1,1), false, false, 2000000);
//
//	// Prepare Streams
//	w.PrepareStreams();
//
//	// Write header
//	w.WriteHeader();
//
//	// Output stream info
//	w.OutputStreamInfo();
//
//	for (int frame = 1; frame <= 500; frame++)
//	{
//		tr1::shared_ptr<Frame> f = t.GetFrame(frame);
//		if (f)
//		{
//			//f->AddOverlayNumber(0);
//			//if (frame >= 1 && frame <= 22)
//			//	f->DisplayWaveform();
//
//			// Write frame
//			//cout << "queue frame " << frame << endl;
//			cout << "queue frame " << frame << " (" << f->number << ", " << f << ")" << endl;
//			w.WriteFrame(f);
//		}
//	}
//
//	// Write Footer
//	w.WriteTrailer();
//
//	// Close writer & reader
//	w.Close();
//
//	// Close timeline
//	t.Close();
//
//	cout << "Successfully Finished Timeline DEMO" << endl;
//	return 0;




	// Create timeline
//	Framerate fps(30000,1000);
//	Timeline t(640, 480, fps);
//
//	// Add some clips
//	Clip c1("../../src/examples/test.mp4");
//	c1.Layer(2);
//	c1.Position(0.0);
//	c1.rotation.AddPoint(60, 360);
//
//	// Add clips
//	t.AddClip(&c1);
//
//	// Request frames
//	for (int x=1; x<=100; x++)
//		t.GetFrame(x);
//
//	// Close timeline
//	t.Close();
//
//	cout << "Successfully Finished Timeline DEMO" << endl;
//	return 0;



	//openshot::ImageReader i("/home/jonathan/Apps/videcho_site/media/logos/watermark3.png");
	//openshot::Frame* overlay = i.GetFrame(1);
	//i.DisplayInfo();

	//	openshot::FFmpegReader r("../../src/examples/test.mp4");
	//	openshot::FFmpegReader r("../../src/examples/test1.mp4");
	//	openshot::FFmpegReader r("../../src/examples/piano.wav");
	//	openshot::FFmpegReader r("/home/jonathan/Videos/big-buck-bunny_trailer.webm");

		openshot::FFmpegReader r("/home/jonathan/Desktop/test2.flv");
	//	openshot::FFmpegReader r("/home/jonathan/Videos/OpenShot_Now_In_3d.mp4");
	//	openshot::FFmpegReader r("/home/jonathan/Videos/sintel_trailer-720p.mp4");
	//	openshot::FFmpegReader r("/home/jonathan/Aptana Studio Workspace/OpenShotLibrary/src/examples/piano.wav");
	//	openshot::FFmpegReader r("/home/jonathan/Music/Army of Lovers/Crucified/Army of Lovers - Crucified [Single Version].mp3");
	//	openshot::FFmpegReader r("/home/jonathan/Documents/OpenShot Art/test.jpeg");
	//	openshot::FFmpegReader r("/home/jonathan/Videos/60fps.mp4");
	//	openshot::FFmpegReader r("/home/jonathan/Aptana Studio Workspace/OpenShotLibrary/src/examples/asdf.wdf");



		// Display debug info
		r.Open();
		r.DisplayInfo();

//		for (int frame = 1; frame <= 300; frame++)
//		{
//			tr1::shared_ptr<Frame> f = r.GetFrame(frame);
//		}
//		return 0;





		// Create a writer
		FFmpegWriter w("/home/jonathan/output.mp4");
		w.DisplayInfo();

		// Set options
		//w.SetAudioOptions(true, "libvorbis", 44100, 2, 128000, false);
		w.SetAudioOptions(true, "libmp3lame", 44100, 2, 128000, false);

		//w.SetVideoOptions(true, "libvpx", Fraction(25,1), 320, 240, Fraction(1,1), false, false, 2000000);
		w.SetVideoOptions(true, "libx264", Fraction(25,1), 320, 240, Fraction(1,1), false, false, 2000000);
		//w.SetVideoOptions(true, "libtheora", Fraction(25,1), 320, 240, Fraction(1,1), false, false, 2000000);

		// Prepare Streams
		w.PrepareStreams();

		// Set Options
//		w.SetOption(VIDEO_STREAM, "quality", "good");
//		w.SetOption(VIDEO_STREAM, "g", "120");
//		w.SetOption(VIDEO_STREAM, "qmin", "11");
//		w.SetOption(VIDEO_STREAM, "qmax", "51");
//		w.SetOption(VIDEO_STREAM, "profile", "0");
//		w.SetOption(VIDEO_STREAM, "speed", "0");
//		w.SetOption(VIDEO_STREAM, "level", "216");
//		w.SetOption(VIDEO_STREAM, "rc_lookahead", "16");
//		w.SetOption(VIDEO_STREAM, "rc_min_rate", "100000");
//		w.SetOption(VIDEO_STREAM, "rc_max_rate", "24000000");
//		w.SetOption(VIDEO_STREAM, "slices", "4");
//		w.SetOption(VIDEO_STREAM, "arnr_max_frames", "7");
//		w.SetOption(VIDEO_STREAM, "arnr_strength", "5");
//		w.SetOption(VIDEO_STREAM, "arnr_type", "3");

		// Write header
		w.WriteHeader();

		// Output stream info
		w.OutputStreamInfo();

		//Frame *f = r.GetFrame(1);

		//for (int frame = 131; frame >= 1; frame--)
		for (int frame = 1; frame <= 300; frame++)
		{
			tr1::shared_ptr<Frame> f = r.GetFrame(frame);
			//f->AddOverlayNumber(0);
			//f->Display();

			// Write frame
			cout << "queue frame " << frame << endl;
			w.WriteFrame(f);
		}

		// Write Footer
		w.WriteTrailer();

		// Close writer & reader
		w.Close();
		r.Close();


		cout << "Successfully executed Main.cpp!" << endl;

	return 0;
}

