#include "plugin.hpp"


struct Mavka : Module {
	enum ParamId {
		PITCH_PARAM,
		SINE_AMOUNT_PARAM,
		TRIANGLE_AMOUNT_PARAM,
		SAW_AMOUNT_PARAM,
		SQUARE_AMOUNT_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		PITCH_INPUT,
		SINE_CV_INPUT,
		TRIANGLE_CV_INPUT,
		SAW_CV_INPUT,
		SQUARE_CV_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		TRIANGLE_OUTPUT,
		SINE_OUTPUT,
		SAW_OUTPUT,
		SQUARE_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		LIGHTS_LEN
	};

	Mavka() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configParam(PITCH_PARAM, 0.f, 1.f, 0.f, "Pitch");
		configParam(SINE_AMOUNT_PARAM, 0.f, 1.f, 1.f, "Sine amount / offset");
		configParam(TRIANGLE_AMOUNT_PARAM, 0.f, 1.f, 1.f, "Triangle amount / offset");
		configParam(SAW_AMOUNT_PARAM, 0.f, 1.f, 1.f, "Saw amount / offset");
		configParam(SQUARE_AMOUNT_PARAM, 0.f, 1.f, 1.f, "Square amount / offset");
		configInput(PITCH_INPUT, "Pitch CV");
		configInput(SINE_CV_INPUT, "Sine amount CV");
		configInput(TRIANGLE_CV_INPUT, "Triangle amount CV");
		configInput(SAW_CV_INPUT, "Saw amount CV");
		configInput(SQUARE_CV_INPUT, "Square amount CV");
		configOutput(TRIANGLE_OUTPUT, "Triangle out");
		configOutput(SINE_OUTPUT, "Sine out");
		configOutput(SAW_OUTPUT, "Saw out");
		configOutput(SQUARE_OUTPUT, "Square out");
	}

	float phase = 0.f;

	void process(const ProcessArgs& args) override {
		float pitch = params[PITCH_PARAM].getValue();
		pitch += inputs[PITCH_INPUT].getVoltage();
		pitch = clamp(pitch, -4.f, 4.f);
		// The default pitch is C4 = 261.6256f
		float freq = dsp::FREQ_C4 * std::pow(2.f, pitch);

		phase += freq * args.sampleTime;
		if (phase >= 0.5f)
			phase -= 1.f;

		float sine = std::sin(2.f * M_PI * phase);
		float square = phase;
		float tri = (abs(phase) * -2.f + 0.5f) * 2.f;
		float saw = phase * 2;

		if (phase < 0) {
			square = -1;
		} else {
			square = 1;
		}

		float sineAmount = params[SINE_AMOUNT_PARAM].getValue();
		sineAmount += inputs[SINE_CV_INPUT].getVoltage();
		sineAmount = clamp(sineAmount, 0.f, 1.f);

		float triAmount = params[TRIANGLE_AMOUNT_PARAM].getValue();
		triAmount += inputs[TRIANGLE_CV_INPUT].getVoltage();
		triAmount = clamp(triAmount, 0.f, 1.f);
		
		float sawAmount = params[SAW_AMOUNT_PARAM].getValue();
		sawAmount += inputs[SAW_CV_INPUT].getVoltage();
		sawAmount = clamp(sawAmount, 0.f, 1.f);

		float squareAmount = params[SQUARE_AMOUNT_PARAM].getValue();
		squareAmount += inputs[SQUARE_CV_INPUT].getVoltage();
		squareAmount = clamp(squareAmount, 0.f, 1.f);

		outputs[SINE_OUTPUT].setVoltage(5.f * sine * sineAmount);
		outputs[TRIANGLE_OUTPUT].setVoltage(5.f * tri * triAmount);
		outputs[SQUARE_OUTPUT].setVoltage(5.f * square * squareAmount);
		outputs[SAW_OUTPUT].setVoltage(5.f * saw * sawAmount);
	}
};


struct MavkaWidget : ModuleWidget {
	MavkaWidget(Mavka* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/Mavka.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<RoundHugeBlackKnob>(mm2px(Vec(31.307, 24.753)), module, Mavka::PITCH_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(12.738, 95.185)), module, Mavka::SINE_AMOUNT_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(24.91, 95.185)), module, Mavka::TRIANGLE_AMOUNT_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(36.786, 95.185)), module, Mavka::SAW_AMOUNT_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(48.958, 95.185)), module, Mavka::SQUARE_AMOUNT_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(30.82, 51.186)), module, Mavka::PITCH_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(12.738, 81.956)), module, Mavka::SINE_CV_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(24.91, 81.956)), module, Mavka::TRIANGLE_CV_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(36.786, 81.956)), module, Mavka::SAW_CV_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(48.958, 81.956)), module, Mavka::SQUARE_CV_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(24.638, 107.404)), module, Mavka::TRIANGLE_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(12.948, 107.654)), module, Mavka::SINE_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(36.514, 107.404)), module, Mavka::SAW_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(48.972, 107.404)), module, Mavka::SQUARE_OUTPUT));
	}
};


Model* modelMavka = createModel<Mavka, MavkaWidget>("Mavka");