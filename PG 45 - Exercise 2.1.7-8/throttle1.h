#ifndef ALAYO_THROTTLE1
#define ALAYO_THROTTLE1

namespace Alayo_2
{
	class throttle1
	{
	public:
		throttle1();
		throttle1(int size);
		void shutoff() { position = 0; }
		void shift(int amount);
		double flow() const { return position / double(top_position); }
		bool is_on() const { return position > 0; }
		bool is_half_full() const {	return (flow() > 0.5 && flow() < top_position); }

	private:
		int top_position;
		int position;
	};
}
#endif ALAYO_THROTTLE1

