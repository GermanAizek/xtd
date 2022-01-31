/// @file
/// @brief Contains xtd::forms::style_sheets::style_sheet class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <map>
#include <vector>
#include <xtd/event_handler.h>
#include <xtd/iequatable.h>
#include <xtd/object.h>
#include <xtd/uri.h>
#include <xtd/web/css/css_reader.h>
#include "../../forms_export.h"
#include "button.h"
#include "form.h"
#include "label.h"
#include "pseudo_state.h"
#include "system_colors.h"
#include "theme.h"

/// @cond
class __test_style_sheet__; // Necessary for the test unit to access the private member functions
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The xtd::forms::style_sheets::style_sheet allows you to specify an xtd style sheet.
      /// @code
      /// class forms_export_ style_sheet final : public xtd::iequatable<style_sheet>, public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::style_sheet
      /// @par Implements
      /// xtd::iequatable <>
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks This class is used by xtd::forms::style_sheets::ibox_model.
      /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_overview.md">Style sheets overview</a>.
      class forms_export_ style_sheet final : public xtd::iequatable<style_sheet>, public xtd::object {
      public:
        /// @name Alias
 
        /// @{
        /// @brief Represents a style sheet buttons collection.
        using buttons_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::button>;
        /// @brief Represents a style sheet controls collection.
        using controls_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::control>;
        /// @brief Represents a style sheet forms collection.
        using forms_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::form>;
        /// @brief Represents a style sheet labels collection.
        using labels_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::label>;
        /// @brief Represents a style_sheets collection.
        using style_sheets_t = std::map<xtd::ustring, style_sheet>;
        /// @}
        
        /// @name Fields
        
        /// @{
        /// @brief Provides an empty xtd::forms::style_sheets::style_sheet object.
        static const style_sheet empty;
        /// @}

        /// @name Constructors
        
        /// @brief Initialize a new xtd::forms::style_sheets::style_sheet instance.
        style_sheet() = default;
        /// @brief Initialize a new xtd::forms::style_sheets::style_sheet instance from specified css forrmated text.
        /// @param css_text The css forrmated text that contains the style sheet definition.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_overview.md">Style sheets overview</a>.
        explicit style_sheet(const xtd::ustring& css_text);

        /// @cond
        style_sheet(const style_sheet&) = default;
        style_sheet(style_sheet&&) = default;
        style_sheet& operator=(const style_sheet&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the style sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        const xtd::forms::style_sheets::button& button() const noexcept;
        /// @brief Gets the style sheet button for specified pseudo state.
        /// @return A style_sheet button.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        const xtd::forms::style_sheets::button& button(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet buttons collection of this instance.
        /// @return The style sheet buttons collection.
        const buttons_t& buttons() const noexcept;

        /// @brief Gets the style sheet control for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet control for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        const xtd::forms::style_sheets::control& control() const noexcept;
        /// @brief Gets the style sheet control for specified pseudo state.
        /// @return A style_sheet control.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        const xtd::forms::style_sheets::control& control(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet controls collection of this instance.
        /// @return The style sheet controls collection.
        const controls_t& controls() const noexcept;

        /// @brief Gets current xtd::forms::style_sheets::style_sheet style sheet.
        /// @return The current xtd::forms::style_sheets::style_sheet style sheet.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_overview.md">Style sheets overview</a>.
        static const style_sheet& current_style_sheet() noexcept;
        /// @brief Sets current xtd::forms::style_sheets::style_sheet style sheet.
        /// @param value The current xtd::forms::style_sheets::style_sheet style sheet.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_overview.md">Style sheets overview</a>.
        static void current_style_sheet(const style_sheet& value);

        /// @brief Gets the style sheet form for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet form for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        const xtd::forms::style_sheets::form& form() const noexcept;
        /// @brief Gets the style sheet form for specified pseudo state.
        /// @return A style_sheet form.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        const xtd::forms::style_sheets::form& form(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet forms collection of this instance.
        /// @return The style sheet forms collection.
        const forms_t& forms() const noexcept;

        /// @brief Gets the style sheet label for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet label for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        const xtd::forms::style_sheets::label& label() const noexcept;
        /// @brief Gets the style sheet label for specified pseudo state.
        /// @return A style_sheet label.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        const xtd::forms::style_sheets::label& label(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet labels collection of this instance.
        /// @return The style sheet labels collection.
        const labels_t& labels() const noexcept;

        /// @brief Gets the installed xtd::forms::style_sheets::style_sheet style sheets.
        /// @return The installed xtd::forms::style_sheets::style_sheet style sheets.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_overview.md">Style sheets overview</a>.
        static const style_sheets_t& style_sheets() noexcept;

        /// @brief Gets The style sheet system colors of this instance.
        /// @return The style sheet systel colors collection.
        const xtd::forms::style_sheets::system_colors& system_colors() const noexcept;
        
        /// @brief Gets system xtd::forms::style_sheets::style_sheet style sheet.
        /// @return The system xtd::forms::style_sheets::style_sheet style sheet.
        /// @remarks The system style sheet is the style sheet corresponding to the current Operating System and the current Desktop Environment.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_overview.md">Style sheets overview</a>.
        static const style_sheet& system_style_sheet() noexcept;
        
        /// @brief Gets The style sheet theme of this instance.
        /// @return The style sheet theme collection.
        const xtd::forms::style_sheets::theme& theme() const noexcept;
        /// @}

        /// @name Methods

        /// @{
        bool equals(const object& other) const noexcept override;
        bool equals(const style_sheet& other) const noexcept override;

        /// @brief Gets the style sheet buttons collection from specified css string.
        /// @param css_text The css string that contains button definition.
        /// @return The style sheet buttons collection.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_overview.md">Style sheets overview</a>.
        static buttons_t button_from_css(const  xtd::ustring& css_text);

        /// @brief Gets the style sheet controls collection from specified css string.
        /// @param css_text The css string that contains control definition.
        /// @return The style sheet controls collection.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_overview.md">Style sheets overview</a>.
        static controls_t control_from_css(const  xtd::ustring& css_text);

        /// @brief Gets the style sheet forms collection from specified css string.
        /// @param css_text The css string that contains forms definition.
        /// @return The style sheet forms collection.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_overview.md">Style sheets overview</a>.
        static forms_t form_from_css(const  xtd::ustring& css_text);

        /// @brief Gets the style sheet system colors from specified css string.
        /// @param css_text The css string that contains system colors definition.
        /// @return The style sheet system colors.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_overview.md">Style sheets overview</a>.
        static xtd::forms::style_sheets::system_colors system_colors_from_css(const xtd::ustring& css_text);

        /// @brief Gets the style sheet theme from specified css string.
        /// @param css_text The css string that contains theme definition.
        /// @return The style sheet theme.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_overview.md">Style sheets overview</a>.
        static xtd::forms::style_sheets::theme theme_from_css(const xtd::ustring& css_text);
        /// @}
        
        /// @name Events
        
        /// @{
        /// @brief Occurs when the value of the xtd::forms::style_sheets::style_sheet::current_style_sheet property changes.
        /// @ingroup events
        /// @remarks This event is raised if the xtd::forms::style_sheets::style_sheet::current_style_sheet property is changed by either a programmatic modification or user interaction.
        /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
        static event<style_sheet, event_handler> current_style_sheet_changed;
        /// @}
        
      private:
        friend class ::__test_style_sheet__; // Necessary for the test unit to access the private member functions
        border_color border_color_from_css(const xtd::ustring& css_text, const border_color& default_value) const noexcept;
        border_style border_style_from_css(const ustring& text, const border_style& default_value) const noexcept;
        xtd::drawing::color color_from_css(const xtd::ustring& css_text, const xtd::drawing::color& default_value) const noexcept;
        background_image background_image_from_css(const xtd::ustring& css_text, const background_image& default_value) const noexcept;
        length length_from_css(const xtd::ustring& css_text, const length& default_value) const noexcept;
        xtd::ustring string_from_css(const xtd::ustring& css_text, const xtd::ustring& default_value) const noexcept;
        xtd::uri uri_from_css(const xtd::ustring& css_text, const xtd::uri& default_value) const noexcept;

        static void initilize();
        static void on_current_style_sheet_changed(const xtd::event_args& e);
        std::vector<xtd::ustring> split_colors_from_text(const xtd::ustring& text) const noexcept;
        void system_color_reader(xtd::web::css::selector_map::const_iterator& selectors_iterator, xtd::forms::style_sheets::system_colors& colors) const noexcept;
        static style_sheet system_style_sheet_gnome_dark() noexcept;
        static style_sheet system_style_sheet_gnome_light() noexcept;
        static style_sheet system_style_sheet_kde_dark() noexcept;
        static style_sheet system_style_sheet_kde_light() noexcept;
        static style_sheet system_style_sheet_macos_dark() noexcept;
        static style_sheet system_style_sheet_macos_light() noexcept;
        static style_sheet system_style_sheet_unknown_dark() noexcept;
        static style_sheet system_style_sheet_unknown_light() noexcept;
        static style_sheet system_style_sheet_windows_dark() noexcept;
        static style_sheet system_style_sheet_windows_light() noexcept;
        void theme_reader(xtd::web::css::selector_map::const_iterator& selectors_iterator, xtd::forms::style_sheets::theme& theme) const noexcept;
        bool try_parse_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_hex_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_linear_gradient(const xtd::ustring& text, background_image& result) const noexcept;
        bool try_parse_named_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_rgb_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_rgba_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_argb_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_hsv_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_hsva_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_ahsv_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_hsl_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_hsla_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_ahsl_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_system_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_uri(const xtd::ustring& text, xtd::uri& result) const noexcept;

        buttons_t buttons_;
        controls_t controls_;
        forms_t forms_;
        labels_t labels_;
        static style_sheet current_style_sheets_;
        static style_sheets_t style_sheets_;
        xtd::forms::style_sheets::system_colors system_colors_;
        xtd::forms::style_sheets::theme theme_;
      };
    }
  }
}
