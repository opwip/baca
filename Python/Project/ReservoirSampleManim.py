from manim import *

class ReservoirSamplingAnimation(Scene):
    def construct(self):
        # Title
        title = Text("Reservoir Sampling", font_size=40).to_edge(UP)
        self.play(Write(title))
        self.wait(1)

        # Initialize parameters
        k = 3  # Reservoir size
        n = 8  # Total items in stream
        reservoir = [None] * k  # Track reservoir items
        colors = [BLUE, GREEN, RED, YELLOW, PURPLE, ORANGE, PINK, TEAL]

        # Create reservoir slots (rectangles)
        slot_width = 2
        slot_height = 1
        
        stream_slots = VGroup(*[
            Rectangle(width=1, height=0.5, fill_opacity=0.2, color=WHITE)
            for _ in range(n)
        ]).arrange(RIGHT, buff=0.5).shift(UP * 1)
        
        slots = VGroup(*[
            Rectangle(width=slot_width, height=slot_height, fill_opacity=0.2, color=WHITE)
            for _ in range(k)
        ]).arrange(RIGHT, buff=0.5).shift(DOWN * 2)
        
        # Initialize slot labels as VGroup to manage them more easily
        slot_labels = VGroup()
        for slot in slots:
            label = Text("Empty", font_size=24).move_to(slot)
            slot_labels.add(label)
            
        stream_labels = VGroup()
        for i in range(len(stream_slots)):
            label = Text(f"{i+1}", font_size=24).move_to(stream_slots[i])
            stream_labels.add(label)

        # Display reservoir
        reservoir_label = Text("Reservoir (k=3)", font_size=30).next_to(slots, UP)
        self.play(Create(slots), Write(reservoir_label), Write(slot_labels))
        self.wait(1)

        # Stream of items (circles with numbers)
        stream_label = Text("Stream", font_size=30).to_edge(LEFT).shift(UP * 2)
        self.play(Write(stream_label))
        self.play(Create(stream_slots), Write(stream_labels))
        self.wait(1)

        # Keep track of item representations in the reservoir
        reservoir_items = [None] * k
        
        # Process each item in the stream
        for i in range(1, n + 1):
            # Create item (circle with number)
            item = Circle(radius=0.5, color=colors[(i-1) % len(colors)], fill_opacity=0.5)
            item_label = Text(str(i), font_size=24, color=WHITE).move_to(item)
            item_group = VGroup(item, item_label).move_to(stream_slots[i-1])

            # Animate item arrival
            self.play(FadeIn(item_group), run_time=0.5)
            # self.play(item_group.animate.shift(RIGHT * 4), run_time=1)

            # If reservoir not full, add item

            
            if i <= k:
                slot_idx = i - 1
                reservoir[slot_idx] = i
                
                # Create a copy of the item to place in the reservoir
                item_copy = item_group.copy()
                
                # Remove the "Empty" label and add the new item
                self.play(
                    FadeOut(slot_labels[slot_idx]),
                    item_copy.animate.move_to(slots[slot_idx]),
                    run_time=1
                )
                
                # Store the item copy in our tracking list
                reservoir_items[slot_idx] = item_copy
                self.add(item_copy)
                
                # Remove original item
                self.play(FadeOut(item_group), run_time=0.5)
                
            else:
                # Calculate probability of inclusion
                prob = k / i
                prob_text = MathTex(f"P(\\text{{include {i}}}) = \\frac{{{k}}}{{{i}}} = {prob:.2f}", font_size=30).to_edge(RIGHT)
                self.play(Write(prob_text))

                # Simulate random decision (highlight if included)
                random_value = np.random.random()
                if random_value < prob:
                    # Choose random slot to replace
                    replace_idx = np.random.randint(0, k)
                    
                    reservoir[replace_idx] = i
                    index_text = Text(f"Random Insertion index: {replace_idx}", font_size=16).to_edge(LEFT).shift(DOWN * 2)
                    index_text.set_color(YELLOW)
                    self.play(Write(index_text))
                    
                    # Create a copy of the item to place in the reservoir
                    item_copy = item_group.copy()
                    
                    # Remove the old item and add the new one
                    if reservoir_items[replace_idx] is not None:
                        self.play(
                            FadeOut(reservoir_items[replace_idx]),
                            item_copy.animate.move_to(slots[replace_idx]),
                            run_time=1
                        )
                    else:
                        self.play(
                            item_copy.animate.move_to(slots[replace_idx]),
                            run_time=1
                        )
                    
                    # Store the new item in our tracking list
                    reservoir_items[replace_idx] = item_copy
                    self.add(item_copy)
                    
                    # Show indication that the slot was replaced
                    self.play(Indicate(slots[replace_idx], color=YELLOW), run_time=0.5)
                    
                    # Remove original item
                    self.play(FadeOut(item_group), run_time=0.5)
                    self.play(FadeOut(index_text), run_time=0.1)
                else:
                    # Item not included
                    self.play(item_group.animate.shift(UP * 2), FadeOut(item_group), run_time=1)

                self.play(FadeOut(prob_text))

            self.wait(0.5)

        # Final result
        final_text = Text("Final Sample:", font_size=30).next_to(slots, DOWN)
        final_sample = Text(str(reservoir), font_size=30).next_to(final_text, RIGHT)
        self.play(Write(final_text), Write(final_sample))
        self.wait(2)

        # Fade out everything
        self.play(
            *[FadeOut(mob) for mob in [title, slots, reservoir_label, stream_label, final_text, final_sample]], 
            *[FadeOut(item) for item in reservoir_items if item is not None]
        )
        self.wait(1)