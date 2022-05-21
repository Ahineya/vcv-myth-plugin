#include "plugin.hpp"


struct Molphar : Module {
	enum ParamId {
		TEMPO_PARAM,
		STEP_1_1_PARAM,
		STEP_1_2_PARAM,
		STEP_1_3_PARAM,
		STEP_1_4_PARAM,
		STEP_1_5_PARAM,
		STEP_1_6_PARAM,
		STEP_1_7_PARAM,
		STEP_1_8_PARAM,
		STEP_2_1_PARAM,
		STEP_2_2_PARAM,
		STEP_2_3_PARAM,
		STEP_2_4_PARAM,
		STEP_2_5_PARAM,
		STEP_2_6_PARAM,
		STEP_2_7_PARAM,
		STEP_2_8_PARAM,
		STEP_3_1_PARAM,
		STEP_3_2_PARAM,
		STEP_3_3_PARAM,
		STEP_3_4_PARAM,
		STEP_3_5_PARAM,
		STEP_3_6_PARAM,
		STEP_3_7_PARAM,
		STEP_3_8_PARAM,
		SINE_AMOUNT_PARAM,
		PROB_1_PARAM,
		PROB_2_PARAM,
		PROB_3_PARAM,
		PROB_4_PARAM,
		PROB_5_PARAM,
		PROB_6_PARAM,
		PROB_7_PARAM,
		PROB_8_PARAM,
		MODE_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		CLOCK_INPUT,
		SINE_CV_INPUT,
		PROB_1_IN_INPUT,
		PROB_2_IN_INPUT,
		PROB_3_IN_INPUT,
		PROB_4_IN_INPUT,
		PROB_5_IN_INPUT,
		PROB_6_IN_INPUT,
		PROB_7_IN_INPUT,
		PROB_8_IN_INPUT,
		MODE_IN_INPUT,
		RESET_INPUT,
		INPUTS_LEN,
	};
	enum OutputId {
		SINE_OUTPUT,
		GATE_1_OUTPUT,
		GATE_2_OUTPUT,
		GATE_3_OUTPUT,
		GATE_4_OUTPUT,
		GATE_5_OUTPUT,
		GATE_6_OUTPUT,
		GATE_7_OUTPUT,
		GATE_8_OUTPUT,
		GATE_OUTPUT,
		OUT_1_OUTPUT,
		OUT_2_OUTPUT,
		OUT_3_OUTPUT,
		OUT_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		TEMPO_LIGHT_LIGHT,
		LIGHT_1_1_LIGHT_G,
		LIGHT_1_1_LIGHT_R,
		LIGHT_1_2_LIGHT_G,
		LIGHT_1_2_LIGHT_R,
		LIGHT_1_3_LIGHT_G,
		LIGHT_1_3_LIGHT_R,
		LIGHT_1_4_LIGHT_G,
		LIGHT_1_4_LIGHT_R,
		LIGHT_1_5_LIGHT_G,
		LIGHT_1_5_LIGHT_R,
		LIGHT_1_6_LIGHT_G,
		LIGHT_1_6_LIGHT_R,
		LIGHT_1_7_LIGHT_G,
		LIGHT_1_7_LIGHT_R,
		LIGHT_1_8_LIGHT_G,
		LIGHT_1_8_LIGHT_R,
		LIGHT_2_1_LIGHT_G,
		LIGHT_2_1_LIGHT_R,
		LIGHT_2_2_LIGHT_G,
		LIGHT_2_2_LIGHT_R,
		LIGHT_2_3_LIGHT_G,
		LIGHT_2_3_LIGHT_R,
		LIGHT_2_4_LIGHT_G,
		LIGHT_2_4_LIGHT_R,
		LIGHT_2_5_LIGHT_G,
		LIGHT_2_5_LIGHT_R,
		LIGHT_2_6_LIGHT_G,
		LIGHT_2_6_LIGHT_R,
		LIGHT_2_7_LIGHT_G,
		LIGHT_2_7_LIGHT_R,
		LIGHT_2_8_LIGHT_G,
		LIGHT_2_8_LIGHT_R,
		LIGHT_3_1_LIGHT_G,
		LIGHT_3_1_LIGHT_R,
		LIGHT_3_2_LIGHT_G,
		LIGHT_3_2_LIGHT_R,
		LIGHT_3_3_LIGHT_G,
		LIGHT_3_3_LIGHT_R,
		LIGHT_3_4_LIGHT_G,
		LIGHT_3_4_LIGHT_R,
		LIGHT_3_5_LIGHT_G,
		LIGHT_3_5_LIGHT_R,
		LIGHT_3_6_LIGHT_G,
		LIGHT_3_6_LIGHT_R,
		LIGHT_3_7_LIGHT_G,
		LIGHT_3_7_LIGHT_R,
		LIGHT_3_8_LIGHT_G,
		LIGHT_3_8_LIGHT_R,
          
		SINE_LIGHT,
		LIGHTS_LEN
	};

	Molphar() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configParam(TEMPO_PARAM, 15.f, 960.f, 120.f, "Tempo", "bpm");
		configParam(STEP_1_1_PARAM, -10.f, 10.f, 0.f, "Step 1-1", "V");
		configParam(STEP_1_2_PARAM, -10.f, 10.f, 0.f, "Step 1-2", "V");
		configParam(STEP_1_3_PARAM, -10.f, 10.f, 0.f, "Step 1-3", "V");
		configParam(STEP_1_4_PARAM, -10.f, 10.f, 0.f, "Step 1-4", "V");
		configParam(STEP_1_5_PARAM, -10.f, 10.f, 0.f, "Step 1-5", "V");
		configParam(STEP_1_6_PARAM, -10.f, 10.f, 0.f, "Step 1-6", "V");
		configParam(STEP_1_7_PARAM, -10.f, 10.f, 0.f, "Step 1-7", "V");
		configParam(STEP_1_8_PARAM, -10.f, 10.f, 0.f, "Step 1-8", "V");
		configParam(STEP_2_1_PARAM, -10.f, 10.f, 0.f, "Step 2-1", "V");
		configParam(STEP_2_2_PARAM, -10.f, 10.f, 0.f, "Step 2-2", "V");
		configParam(STEP_2_3_PARAM, -10.f, 10.f, 0.f, "Step 2-3", "V");
		configParam(STEP_2_4_PARAM, -10.f, 10.f, 0.f, "Step 2-4", "V");
		configParam(STEP_2_5_PARAM, -10.f, 10.f, 0.f, "Step 2-5", "V");
		configParam(STEP_2_6_PARAM, -10.f, 10.f, 0.f, "Step 2-6", "V");
		configParam(STEP_2_7_PARAM, -10.f, 10.f, 0.f, "Step 2-7", "V");
		configParam(STEP_2_8_PARAM, -10.f, 10.f, 0.f, "Step 2-8", "V");
		configParam(STEP_3_1_PARAM, -10.f, 10.f, 0.f, "Step 3-1", "V");
		configParam(STEP_3_2_PARAM, -10.f, 10.f, 0.f, "Step 3-2", "V");
		configParam(STEP_3_3_PARAM, -10.f, 10.f, 0.f, "Step 3-3", "V");
		configParam(STEP_3_4_PARAM, -10.f, 10.f, 0.f, "Step 3-4", "V");
		configParam(STEP_3_5_PARAM, -10.f, 10.f, 0.f, "Step 3-5", "V");
		configParam(STEP_3_6_PARAM, -10.f, 10.f, 0.f, "Step 3-6", "V");
		configParam(STEP_3_7_PARAM, -10.f, 10.f, 0.f, "Step 3-7", "V");
		configParam(STEP_3_8_PARAM, -10.f, 10.f, 0.f, "Step 3-8", "V");
		configParam(PROB_1_PARAM, 0.f, 100.f, 100.f, "Probability 1", "%");
		configParam(PROB_2_PARAM, 0.f, 100.f, 100.f, "Probability 2", "%");
		configParam(PROB_3_PARAM, 0.f, 100.f, 100.f, "Probability 3", "%");
		configParam(PROB_4_PARAM, 0.f, 100.f, 100.f, "Probability 4", "%");
		configParam(PROB_5_PARAM, 0.f, 100.f, 100.f, "Probability 5", "%");
		configParam(PROB_6_PARAM, 0.f, 100.f, 100.f, "Probability 6", "%");
		configParam(PROB_7_PARAM, 0.f, 100.f, 100.f, "Probability 7", "%");
		configParam(PROB_8_PARAM, 0.f, 100.f, 100.f, "Probability 8", "%");
		configParam(MODE_PARAM, 0.f, 2.f, 0.f, "Out track");
		configInput(CLOCK_INPUT, "External clock");
		configInput(RESET_INPUT, "Reset");
		configInput(PROB_1_IN_INPUT, "Probability 1 CV");
		configInput(PROB_2_IN_INPUT, "Probability 2 CV");
		configInput(PROB_3_IN_INPUT, "Probability 3 CV");
		configInput(PROB_4_IN_INPUT, "Probability 4 CV");
		configInput(PROB_5_IN_INPUT, "Probability 5 CV");
		configInput(PROB_6_IN_INPUT, "Probability 6 CV");
		configInput(PROB_7_IN_INPUT, "Probability 7 CV");
		configInput(PROB_8_IN_INPUT, "Probability 8 CV");
		configInput(MODE_IN_INPUT, "Out track CV 0V-2V");
		configOutput(GATE_1_OUTPUT, "Gate 1");
		configOutput(GATE_2_OUTPUT, "Gate 2");
		configOutput(GATE_3_OUTPUT, "Gate 3");
		configOutput(GATE_4_OUTPUT, "Gate 4");
		configOutput(GATE_5_OUTPUT, "Gate 5");
		configOutput(GATE_6_OUTPUT, "Gate 6");
		configOutput(GATE_7_OUTPUT, "Gate 7");
		configOutput(GATE_8_OUTPUT, "Gate 8");
		configOutput(GATE_OUTPUT, "Trigger out");
		configOutput(OUT_1_OUTPUT, "Out 1");
		configOutput(OUT_2_OUTPUT, "Out 2");
		configOutput(OUT_3_OUTPUT, "Out 3");
		configOutput(OUT_OUTPUT, "Out");
	}

	int step = 0;
	int shouldStep = 0;
	float stepPhase = 0;

	int lastClockTrig = 0;

	int stepsOne[8] = { STEP_1_1_PARAM, STEP_1_2_PARAM, STEP_1_3_PARAM, STEP_1_4_PARAM, STEP_1_5_PARAM, STEP_1_6_PARAM, STEP_1_7_PARAM, STEP_1_8_PARAM };
	int stepsTwo[8] = { STEP_2_1_PARAM, STEP_2_2_PARAM, STEP_2_3_PARAM, STEP_2_4_PARAM, STEP_2_5_PARAM, STEP_2_6_PARAM, STEP_2_7_PARAM, STEP_2_8_PARAM };
	int stepsThree[8] = { STEP_3_1_PARAM, STEP_3_2_PARAM, STEP_3_3_PARAM, STEP_3_4_PARAM, STEP_3_5_PARAM, STEP_3_6_PARAM, STEP_3_7_PARAM, STEP_3_8_PARAM };

	int gateOutputs[8] = { GATE_1_OUTPUT, GATE_2_OUTPUT, GATE_3_OUTPUT, GATE_4_OUTPUT, GATE_5_OUTPUT, GATE_6_OUTPUT, GATE_7_OUTPUT, GATE_8_OUTPUT };
	
	int stepProbabilities[8] = { PROB_1_PARAM, PROB_2_PARAM, PROB_3_PARAM, PROB_4_PARAM, PROB_5_PARAM, PROB_6_PARAM, PROB_7_PARAM, PROB_8_PARAM };
	int stepProbabilitiesInputs[8] = { PROB_1_IN_INPUT, PROB_2_IN_INPUT, PROB_3_IN_INPUT, PROB_4_IN_INPUT, PROB_5_IN_INPUT, PROB_6_IN_INPUT, PROB_7_IN_INPUT, PROB_8_IN_INPUT };

	float currentStepProbability = 1.f;
	float shouldCurrentStepOutput = 1.f;

	float trigTimer = 0.f;
	int trigTimerRunning = 0;

	int reset = 0;
	float resetVoltage = 0.f;

	void process(const ProcessArgs& args) override {
		float SR = args.sampleRate;
		float ST = args.sampleTime;
		float sampleLength = 1.0 / SR;

		float bpm = params[TEMPO_PARAM].getValue();
		float bps = bpm / 60;

		stepPhase += bps * args.sampleTime;

		outputs[GATE_OUTPUT].setVoltage(0.f);

		float newResetVoltage = inputs[RESET_INPUT].getNormalVoltage(0.f);
		if (newResetVoltage > 0 && resetVoltage == 0) {
			reset = 1;
			resetVoltage = newResetVoltage;
		}

		if (reset) {
			shouldStep = 0;
			step = 7;
			trigTimer = 0;
			trigTimerRunning = 0;
			stepPhase = 0.f;
			lastClockTrig = 0;
			reset = 0;
		}

		if (newResetVoltage == 0) {
			reset = 0;
			resetVoltage = 0;
		}

		if (shouldStep == 1) {
			step = (step + 1) % 8;
			currentStepProbability = inputs[stepProbabilitiesInputs[step]].getNormalVoltage(params[stepProbabilities[step]].getValue() / 100.f);
			currentStepProbability = clamp(currentStepProbability, 0.f, 1.f);
			shouldCurrentStepOutput = (rand() / static_cast<float>(RAND_MAX)) < currentStepProbability;
			shouldStep = 0;

			if (shouldCurrentStepOutput) {
				trigTimerRunning = 1;
			}
		}

		if (trigTimerRunning) {
			outputs[GATE_OUTPUT].setVoltage(10.f);
			trigTimer += 0.01f;
		}

		if (trigTimer > 1) {
			trigTimerRunning = 0;
			trigTimer = 0.f;
		}

		lights[LIGHT_1_1_LIGHT_G].setBrightness(step == 0 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_1_1_LIGHT_R].setBrightness(step == 0 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);
		lights[LIGHT_2_1_LIGHT_G].setBrightness(step == 0 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_2_1_LIGHT_R].setBrightness(step == 0 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);
		lights[LIGHT_3_1_LIGHT_G].setBrightness(step == 0 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_3_1_LIGHT_R].setBrightness(step == 0 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);

		lights[LIGHT_1_2_LIGHT_G].setBrightness(step == 1 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_1_2_LIGHT_R].setBrightness(step == 1 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);
		lights[LIGHT_2_2_LIGHT_G].setBrightness(step == 1 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_2_2_LIGHT_R].setBrightness(step == 1 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);
		lights[LIGHT_3_2_LIGHT_G].setBrightness(step == 1 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_3_2_LIGHT_R].setBrightness(step == 1 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);

		lights[LIGHT_1_3_LIGHT_G].setBrightness(step == 2 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_1_3_LIGHT_R].setBrightness(step == 2 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);
		lights[LIGHT_2_3_LIGHT_G].setBrightness(step == 2 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_2_3_LIGHT_R].setBrightness(step == 2 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);
		lights[LIGHT_3_3_LIGHT_G].setBrightness(step == 2 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_3_3_LIGHT_R].setBrightness(step == 2 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);

		lights[LIGHT_1_4_LIGHT_G].setBrightness(step == 3 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_1_4_LIGHT_R].setBrightness(step == 3 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);
		lights[LIGHT_2_4_LIGHT_G].setBrightness(step == 3 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_2_4_LIGHT_R].setBrightness(step == 3 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);
		lights[LIGHT_3_4_LIGHT_G].setBrightness(step == 3 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_3_4_LIGHT_R].setBrightness(step == 3 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);

		lights[LIGHT_1_5_LIGHT_G].setBrightness(step == 4 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_1_5_LIGHT_R].setBrightness(step == 4 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);
		lights[LIGHT_2_5_LIGHT_G].setBrightness(step == 4 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_2_5_LIGHT_R].setBrightness(step == 4 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);
		lights[LIGHT_3_5_LIGHT_G].setBrightness(step == 4 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_3_5_LIGHT_R].setBrightness(step == 4 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);

		lights[LIGHT_1_6_LIGHT_G].setBrightness(step == 5 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_1_6_LIGHT_R].setBrightness(step == 5 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);
		lights[LIGHT_2_6_LIGHT_G].setBrightness(step == 5 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_2_6_LIGHT_R].setBrightness(step == 5 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);
		lights[LIGHT_3_6_LIGHT_G].setBrightness(step == 5 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_3_6_LIGHT_R].setBrightness(step == 5 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);

		lights[LIGHT_1_7_LIGHT_G].setBrightness(step == 6 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_1_7_LIGHT_R].setBrightness(step == 6 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);
		lights[LIGHT_2_7_LIGHT_G].setBrightness(step == 6 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_2_7_LIGHT_R].setBrightness(step == 6 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);
		lights[LIGHT_3_7_LIGHT_G].setBrightness(step == 6 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_3_7_LIGHT_R].setBrightness(step == 6 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);

		lights[LIGHT_1_8_LIGHT_G].setBrightness(step == 7 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_1_8_LIGHT_R].setBrightness(step == 7 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);
		lights[LIGHT_2_8_LIGHT_G].setBrightness(step == 7 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_2_8_LIGHT_R].setBrightness(step == 7 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);
		lights[LIGHT_3_8_LIGHT_G].setBrightness(step == 7 ? (shouldCurrentStepOutput ? 1.f : 0.f) : 0.f);
		lights[LIGHT_3_8_LIGHT_R].setBrightness(step == 7 ? (shouldCurrentStepOutput ? 0.f : 1.f) : 0.f);

		float stepGate = stepPhase <= 0.5 ? 10.f : 0.f;
		float clock = inputs[CLOCK_INPUT].getNormalVoltage(stepGate);

		if (clock >= 1.f && lastClockTrig < 1) {
			shouldStep = 1;
		}

		if (clock >= 1.f) {
			clock -= 1.f;
		}

		if (stepPhase >= 1.f) {
			stepPhase -= 1.f;
		}

		lastClockTrig = clock;
		lights[TEMPO_LIGHT_LIGHT].setBrightness(clock >= 0.5f ? 1.f : 0.f);
		
		if (shouldCurrentStepOutput) {
			outputs[OUT_1_OUTPUT].setVoltage(params[stepsOne[step]].getValue());
			outputs[OUT_2_OUTPUT].setVoltage(params[stepsTwo[step]].getValue());
			outputs[OUT_3_OUTPUT].setVoltage(params[stepsThree[step]].getValue());
		}

		float mode = clamp(inputs[MODE_IN_INPUT].getNormalVoltage(params[MODE_PARAM].getValue()), 0.f, 2.f);

		if (mode >= 0 && mode < 1 && shouldCurrentStepOutput) {
			outputs[OUT_OUTPUT].setVoltage(params[stepsOne[step]].getValue());
		}

		if (mode >= 1 && mode < 2 && shouldCurrentStepOutput) {
			outputs[OUT_OUTPUT].setVoltage(params[stepsTwo[step]].getValue());
		}

		if (mode == 2 && shouldCurrentStepOutput) {
			outputs[OUT_OUTPUT].setVoltage(params[stepsThree[step]].getValue());
		}

		for (int i = 0; i < 8; i++) {
			if (i == step && shouldCurrentStepOutput) {
				outputs[gateOutputs[i]].setVoltage(10.f);
			} else {
				outputs[gateOutputs[i]].setVoltage(0.f);
			}
		}
	}
};


struct MolpharWidget : ModuleWidget {
	MolpharWidget(Molphar* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/Molphar.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(12.172, 18.132)), module, Molphar::TEMPO_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(12.172, 31.891)), module, Molphar::STEP_1_1_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(25.779, 31.891)), module, Molphar::STEP_1_2_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(39.386, 31.891)), module, Molphar::STEP_1_3_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(52.993, 31.891)), module, Molphar::STEP_1_4_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(66.601, 31.891)), module, Molphar::STEP_1_5_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(80.208, 31.891)), module, Molphar::STEP_1_6_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(93.815, 31.891)), module, Molphar::STEP_1_7_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(107.422, 31.891)), module, Molphar::STEP_1_8_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(12.172, 47.766)), module, Molphar::STEP_2_1_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(25.779, 47.766)), module, Molphar::STEP_2_2_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(39.386, 47.766)), module, Molphar::STEP_2_3_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(52.993, 47.766)), module, Molphar::STEP_2_4_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(66.601, 47.766)), module, Molphar::STEP_2_5_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(80.208, 47.766)), module, Molphar::STEP_2_6_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(93.815, 47.766)), module, Molphar::STEP_2_7_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(107.422, 47.766)), module, Molphar::STEP_2_8_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(12.172, 63.641)), module, Molphar::STEP_3_1_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(25.779, 63.641)), module, Molphar::STEP_3_2_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(39.386, 63.641)), module, Molphar::STEP_3_3_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(52.993, 63.641)), module, Molphar::STEP_3_4_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(66.601, 63.641)), module, Molphar::STEP_3_5_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(80.208, 63.641)), module, Molphar::STEP_3_6_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(93.815, 63.641)), module, Molphar::STEP_3_7_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(107.422, 63.641)), module, Molphar::STEP_3_8_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(-10.711, 76.683)), module, Molphar::SINE_AMOUNT_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(12.172, 78.457)), module, Molphar::PROB_1_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(25.779, 78.457)), module, Molphar::PROB_2_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(39.386, 78.457)), module, Molphar::PROB_3_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(52.993, 78.457)), module, Molphar::PROB_4_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(66.601, 78.457)), module, Molphar::PROB_5_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(80.208, 78.457)), module, Molphar::PROB_6_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(93.815, 78.457)), module, Molphar::PROB_7_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(107.422, 78.457)), module, Molphar::PROB_8_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(22.626, 112.138)), module, Molphar::MODE_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(23.07, 18.412)), module, Molphar::CLOCK_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(108.033, 18.412)), module, Molphar::RESET_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(12.172, 89.041)), module, Molphar::PROB_1_IN_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(25.779, 89.041)), module, Molphar::PROB_2_IN_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(39.386, 89.041)), module, Molphar::PROB_3_IN_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(52.993, 89.041)), module, Molphar::PROB_4_IN_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(66.601, 89.041)), module, Molphar::PROB_5_IN_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(80.208, 89.041)), module, Molphar::PROB_6_IN_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(93.815, 89.041)), module, Molphar::PROB_7_IN_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(107.422, 89.041)), module, Molphar::PROB_8_IN_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(11.981, 112.303)), module, Molphar::MODE_IN_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(12.172, 100.153)), module, Molphar::GATE_1_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(25.779, 100.153)), module, Molphar::GATE_2_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(39.386, 100.153)), module, Molphar::GATE_3_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(52.993, 100.153)), module, Molphar::GATE_4_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(66.601, 100.153)), module, Molphar::GATE_5_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(80.208, 100.153)), module, Molphar::GATE_6_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(93.815, 100.153)), module, Molphar::GATE_7_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(107.422, 100.153)), module, Molphar::GATE_8_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(52.993, 112.965)), module, Molphar::GATE_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(75.699, 112.965)), module, Molphar::OUT_1_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(86.283, 112.965)), module, Molphar::OUT_2_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(96.866, 112.965)), module, Molphar::OUT_3_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(108.033, 112.965)), module, Molphar::OUT_OUTPUT));

		addChild(createLightCentered<SmallLight<YellowLight>>(mm2px(Vec(15.989, 22.17)), module, Molphar::TEMPO_LIGHT_LIGHT));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(15.989, 35.928)), module, Molphar::LIGHT_1_1_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(29.748, 35.928)), module, Molphar::LIGHT_1_2_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(43.506, 35.928)), module, Molphar::LIGHT_1_3_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(56.735, 35.928)), module, Molphar::LIGHT_1_4_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(70.493, 35.928)), module, Molphar::LIGHT_1_5_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(84.252, 35.928)), module, Molphar::LIGHT_1_6_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(98.01, 35.928)), module, Molphar::LIGHT_1_7_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(111.239, 35.928)), module, Molphar::LIGHT_1_8_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(15.989, 51.803)), module, Molphar::LIGHT_2_1_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(29.748, 51.803)), module, Molphar::LIGHT_2_2_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(43.506, 51.803)), module, Molphar::LIGHT_2_3_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(56.735, 51.803)), module, Molphar::LIGHT_2_4_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(70.493, 51.803)), module, Molphar::LIGHT_2_5_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(84.252, 51.803)), module, Molphar::LIGHT_2_6_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(98.01, 51.803)), module, Molphar::LIGHT_2_7_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(111.239, 51.803)), module, Molphar::LIGHT_2_8_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(15.989, 67.678)), module, Molphar::LIGHT_3_1_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(29.748, 67.678)), module, Molphar::LIGHT_3_2_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(43.506, 67.678)), module, Molphar::LIGHT_3_3_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(56.735, 67.678)), module, Molphar::LIGHT_3_4_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(70.493, 67.678)), module, Molphar::LIGHT_3_5_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(84.252, 67.678)), module, Molphar::LIGHT_3_6_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(98.01, 67.678)), module, Molphar::LIGHT_3_7_LIGHT_G));
		addChild(createLightCentered<SmallLight<GreenRedLight>>(mm2px(Vec(111.239, 67.678)), module, Molphar::LIGHT_3_8_LIGHT_G));
	}
};


Model* modelMolphar = createModel<Molphar, MolpharWidget>("Molphar");